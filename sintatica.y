%{
#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <set> // Adicionado para o set de variáveis alocadas

#define YYSTYPE atributos

using namespace std;

// Contadores globais
int qntdVariaveisTemp = 0;
int contador_rotulos = 0;

// Constante para o buffer do scan
#define SCAN_BUFFER_SIZE 1024

// Pilhas para controle de laços (break/continue)
stack<string> pilhaRotulosFimLoop;
stack<string> pilhaRotulosProxIteracao;

// --- LÓGICA DE STRINGS (DO SEGUNDO CÓDIGO) ---
// Conjunto para rastrear labels de strings que foram alocadas com malloc e precisam de free()
set<string> variaveisAlocadas;

// Estrutura para guardar informações da função (do primeiro código)
struct TIPO_FUNCAO {
    string tipoRetorno;
    vector<string> tiposParametros;
};

// A tabela de símbolos para funções (do primeiro código)
map<string, TIPO_FUNCAO> tabelaFuncoes;

// Atributos para os nós da árvore sintática
// O campo 'tamanho' foi adicionado, conforme o segundo código.
struct atributos 
{
    string label;
    string traducao;
    string tipo;
    int tamanho; // Campo adicionado do segundo código
};

// Estrutura para os símbolos na tabela
typedef struct
{
    string nomeVariavel; // nome no código fonte
    string tipoVariavel; // int, float, double
    string label; // nome no código intermediário (ex: T1, T2)

    bool isArray = false;
    int arraySize = 0;
    int arraySize2 = 0;
    bool isParam = false; // Campo do primeiro código para diferenciar parâmetros

   int getTamanhoTotal() const {
        return arraySize * (arraySize2 > 0 ? arraySize2 : 1);
    }

} TIPO_SIMBOLO;

// Protótipos de funções
int yylex(void);
void yyerror(string);

// Variáveis e estruturas de dados do compilador
set<pair<string,string>> temporarias;
vector<map<string, TIPO_SIMBOLO>> pilhaTabelasSimbolos;
stack<pair<string, string>> pilhaExprSwitch;
vector<TIPO_SIMBOLO> todosOsSimbolos; // <-- ADICIONE ESTA LINHA

// Funções de manipulação da Tabela de Símbolos
bool verificaTabelaSimbolos(string nome);
TIPO_SIMBOLO pegaVariavelTabelaSimbolos(string nome);
void printTabelaSimbolos();
void entraEscopo();
void saiEscopo();

// Funções para inserir na Tabela de Símbolos
void insereFixasTabelaSimbolos(string nome, string tipo, bool ehArray = false, int tamanhoArray = 0, int tamanhoArray2 = 0, bool ehParam = false);
string insereTemporariasTabelaSimbolos(string nome, string tipo);

// Funções auxiliares de geração de código
string novo_rotulo();
string geraNomeTemp(string tipo);
string pegaTipo(string tipo);
string infereTipo(string tipo1, string tipo2);
string pegaBooleano(string valor);
int tamanho_string(string texto);

bool debug = false;
#define true 1
#define false 0

extern int yylinha;

%}

// Definição dos Tokens
%token TK_TIPO TK_ID TK_RETURN
%token TK_INT TK_FLOAT TK_BOOLEAN TK_CHAR TK_STRING
%token TK_MAIOR_IGUAL TK_MENOR_IGUAL TK_DIFERENTE TK_IGUAL TK_E_LOGICO TK_OU_LOGICO TK_NEGACAO
%token TK_IF TK_ELSE TK_WHILE TK_DO TK_FOR TK_IN TK_SWITCH TK_CASE TK_BREAK TK_DEFAULT TK_CONTINUE
%token TK_INCREMENTO TK_DECREMENTO TK_MAIS_IGUAL TK_MENOS_IGUAL TK_MULT_IGUAL TK_DIV_IGUAL TK_POTENCIA
%token TK_PRINT TK_SCAN
%token FIM_LINHA

%start START

%%

START
    : { entraEscopo(); } LISTA_FUNCOES
    {
        if(debug) cout << "[DEBUG] Árvore completa gerada. Tradução:\n";

        // Cabeçalhos C padrão
        string cabecalho = "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <math.h>\n\n";
        string defines = "#define true 1\n#define false 0\n\n";

        // Função auxiliar para strlen (CORPO COMPLETO RESTAURADO)
        string funcao_meu_strlen = "int meu_strlen(char* v0) {\n"
            "\tint v1;\n"
            "\tint t1;\n\tint t2;\n\tint t3;\n\tint t4;\n\tint t5;\n\tint t7;\n\tint t8;\n\tint t9;\n\tint t10;\n\tint t11;\n"
            "\tchar t6;\n\n"
            "\tt1 = (v0 == NULL);\n"
            "\tt2 = !t1;\n"
            "\tif (t2) goto R0;\n\n"
            "\tt3 = 0;\n"
            "\treturn t3;\n\n"
            "R0:\n"
            "\tt4 = 0;\n"
            "\tv1 = t4;\n\n"
            "R1:\n"
            "\tt5 = v1;\n"
            "\tt6 = v0[t5];\n"
            "\tt7 = (t6 != '\\0');\n"
            "\tt8 = !t7;\n"
            "\tif (t8) goto R2;\n\n"
            "\tt9 = v1;\n"
            "\tt10 = t9 + 1;\n"
            "\tv1 = t10;\n"
            "\tgoto R1;\n\n"
            "R2:\n"
            "\tt11 = v1;\n"
            "\treturn t11;\n"
            "}\n\n";
        
        // Função auxiliar para potenciação (CORPO COMPLETO)
        string funcao_potencia =
            "float potencia_helper(float base, int expoente) {\n"
            "\tfloat resultado = 1.0;\n"
            "\tint contador = expoente;\n"
            "L_POW_START:\n"
            "\tif (contador <= 0) goto L_POW_END;\n"
            "\tresultado = resultado * base;\n"
            "\tcontador = contador - 1;\n"
            "\tgoto L_POW_START;\n"
            "L_POW_END:\n"
            "\treturn resultado;\n"
            "}\n\n";

        // Geração das declarações de variáveis (LÓGICA CORRIGIDA para vetores)
        string declaracoes = "";
        for (const auto& simbolo : todosOsSimbolos) {
            if (simbolo.isArray) {
                int tamanho = simbolo.getTamanhoTotal();
                declaracoes += "\t" + simbolo.tipoVariavel + " " + simbolo.label + "[" + to_string(tamanho) + "];\n";
            } else {
                if (simbolo.tipoVariavel == "string")
                    declaracoes += "\tchar* " + simbolo.label + " = NULL;\n";
                else
                    declaracoes += "\t" + simbolo.tipoVariavel + " " + simbolo.label + ";\n";
            }
        }

        // Montagem do código final
        cout << cabecalho 
             << defines 
             << declaracoes << "\n" 
             << funcao_meu_strlen 
             << funcao_potencia 
             << $2.traducao << endl;

        saiEscopo();
    } |
;

LISTA_FUNCOES
    : LISTA_FUNCOES FUNCAO
        { $$.traducao = $1.traducao + "\n" + $2.traducao; }
    | LISTA_FUNCOES FIM_LINHA
        { $$ = $1; }
    | /* Vazio */ 
        { $$.traducao = ""; }
;

FUNCAO
    : TK_TIPO TK_ID '(' PARAMS ')' { entraEscopo(); } BLOCO { saiEscopo(); }
    {
        string tipoRetorno = pegaTipo($1.label);
        string nome = $2.label;
        string corpoFuncao = $7.traducao;

        if (nome == "principal")
            nome = "main";

        if (tabelaFuncoes.count(nome)) {
            yyerror("Função '" + nome + "' já foi declarada.");
        } else {
            TIPO_FUNCAO infoFunc;
            infoFunc.tipoRetorno = tipoRetorno;
            tabelaFuncoes[nome] = infoFunc;
            if(debug) cout << "[DEBUG] Função '" << nome << "' inserida na tabela de funções.\n";
        }
        
        // Se esta é a função main, injeta o código para liberar a memória alocada
        if (nome == "main") {
            string frees = "";
            if (!variaveisAlocadas.empty()) {
                frees += "\n";
                for (const auto& varLabel : variaveisAlocadas) {
                    frees += "\tfree(" + varLabel + ");\n";
                }
            }
            // Insere os frees antes do final do bloco da função
            corpoFuncao += frees;
        }

        $$.traducao = tipoRetorno + " " + nome + "(" + $4.traducao + ") {\n" + corpoFuncao + "}\n";
    }
;

PARAMS
    : PARAM ',' PARAMS
        { $$.traducao = $1.traducao + ", " + $3.traducao; }
    | PARAM
        { $$ = $1; }
    | /* vazio */
        { $$.traducao = ""; }
;

PARAM
    : TK_TIPO TK_ID
    {
        string tipo = pegaTipo($1.label);
        // Passa 'true' para o último argumento, marcando como parâmetro
        insereFixasTabelaSimbolos($2.label, $1.label, false, 0, 0, true); 

        $$.traducao = tipo + " " + $2.label;
    }
;

CODIGO      :   ITEM CODIGO
            {
                $$.traducao = $1.traducao + $2.traducao;
            }
            |
            {
                $$.traducao = "";
            }
            ;
            
ITEM        : BLOCO_DECL
            {
                $$.traducao = $1.traducao;
            }
            | CMD
            {
                $$.traducao = $1.traducao;
            }
            ;

BLOCO_DECL  : TK_TIPO TK_ID '{' { entraEscopo(); } CMDS '}' FIM_LINHA
            {
                $$.tipo = pegaTipo($1.label); 
                $$.traducao =  $$.tipo + " " + $2.label + "(){\n" + $5.traducao + "}\n"; 
                printTabelaSimbolos();
                saiEscopo();
                if(debug) cout << "[DEBUG] Bloco de declaração identificado.\n";
            }
            | TK_TIPO TK_ID '{' { entraEscopo(); } CMDS '}' // p ele pegar último bloco caso não tenha espaço
            {
                $$.tipo = pegaTipo($1.label);
                $$.traducao =  $$.tipo + " " + $2.label + "(){\n" + $5.traducao + "}\n";
                printTabelaSimbolos();
                saiEscopo();
                if(debug) cout << "[DEBUG] Bloco de declaração identificado.\n";
            }
            | FIM_LINHA
            {
                $$.traducao = "";
            }
            ;

BLOCO       : '{' { entraEscopo(); } CMDS '}'
            {   
                printTabelaSimbolos();
                $$.traducao = $3.traducao;
                saiEscopo();
            }
            ;

CMDS        : CMD CMDS
            {
                $$.traducao = $1.traducao + $2.traducao;
                if(debug) cout << "[DEBUG] Comando processado. Acumulado:\n" << $1.traducao;
            }
            |
            {
                $$.traducao = "";
            }
            ;

CMD         : EXP FIM_LINHA  { $$.traducao = $1.traducao; }
            | DECL           { $$.traducao = $1.traducao; }
            | DECL FIM_LINHA { $$.traducao = $1.traducao; }
            | ATR            { $$.traducao = $1.traducao; }
            | ATR FIM_LINHA  { $$.traducao = $1.traducao; }
            | EXP            { $$.traducao = $1.traducao; }
            | FIM_LINHA      { $$.traducao = "";           }
            | TK_IF '(' EXP ')' BLOCO
            {
                string rotuloFimIf = novo_rotulo();
                string temp_copia = insereTemporariasTabelaSimbolos("", "bool");
                string temp_negada = insereTemporariasTabelaSimbolos("", "bool");

                $$.traducao = $3.traducao +
                                 "\t" + temp_copia + " = " + $3.label + ";\n" +
                                 "\t" + temp_negada + " = !" + temp_copia + ";\n" +
                                 "\tif (" + temp_negada + ") goto " + rotuloFimIf + ";\n" +
                                 $5.traducao +
                                 rotuloFimIf + ":\n";
            }
            | TK_IF '(' EXP ')' BLOCO TK_ELSE BLOCO
            {
                string rotuloElse = novo_rotulo();
                string rotuloFimIfElse = novo_rotulo();
                string temp_copia = insereTemporariasTabelaSimbolos("", "bool");
                string temp_negada = insereTemporariasTabelaSimbolos("", "bool");

                $$.traducao = $3.traducao + 
                                 "\t" + temp_copia + " = " + $3.label + ";\n" +
                                 "\t" + temp_negada + " = !" + temp_copia + ";\n" +
                                 "\tif (" + temp_negada + ") goto " + rotuloElse + ";\n" +
                                 $5.traducao +
                                 "\tgoto " + rotuloFimIfElse + ";\n" +
                                 rotuloElse + ":\n" + 
                                 $7.traducao +
                                 rotuloFimIfElse + ":\n";
            }
            | TK_WHILE '(' EXP ')' { /* Ação em tempo de redução */
                string rotuloTeste = novo_rotulo();
                string rotuloFimWhile = novo_rotulo();
                pilhaRotulosProxIteracao.push(rotuloTeste);
                pilhaRotulosFimLoop.push(rotuloFimWhile); 
            }
            BLOCO
            {
                string rotuloTeste = pilhaRotulosProxIteracao.top();
                string rotuloFimWhile = pilhaRotulosFimLoop.top();

                $$.traducao = rotuloTeste + ":\n" +
                                 $3.traducao +
                                 "\tif (!" + $3.label + ") goto " + rotuloFimWhile + ";\n" +
                                 $6.traducao +
                                 "\tgoto " + rotuloTeste + ";\n" +
                                 rotuloFimWhile + ":\n";

                pilhaRotulosProxIteracao.pop();
                pilhaRotulosFimLoop.pop();
            }
            | TK_DO {
                string rotuloTeste = novo_rotulo();
                string rotuloFimDoWhile = novo_rotulo();
                pilhaRotulosProxIteracao.push(rotuloTeste);
                pilhaRotulosFimLoop.push(rotuloFimDoWhile);
            }
            BLOCO TK_WHILE '(' EXP ')' FIM_LINHA
            {
                string rotuloTeste = pilhaRotulosProxIteracao.top();
                string rotuloFimDoWhile = pilhaRotulosFimLoop.top();
                string rotuloCorpo = novo_rotulo();

                $$.traducao = rotuloCorpo + ":\n" +
                                 $3.traducao +
                                 rotuloTeste + ":\n" +
                                 $6.traducao +
                                 "\tif (" + $6.label + ") goto " + rotuloCorpo + ";\n" + 
                                 rotuloFimDoWhile + ":\n";

                pilhaRotulosProxIteracao.pop();
                pilhaRotulosFimLoop.pop();
            }
            | TK_FOR '(' FOR_INICIA ';' EXP ';' FOR_INCREM ')' {
                string rotuloIncremento = novo_rotulo();
                string rotuloFimFor = novo_rotulo();
                pilhaRotulosProxIteracao.push(rotuloIncremento);
                pilhaRotulosFimLoop.push(rotuloFimFor);
            }
            BLOCO 
            {
                string rotuloIncrementoReal = pilhaRotulosProxIteracao.top();
                string rotuloFimForReal = pilhaRotulosFimLoop.top();
                string rotuloTesteReal = novo_rotulo();

                $$.traducao = $3.traducao;
                $$.traducao += rotuloTesteReal + ":\n";
                $$.traducao += $5.traducao;
                $$.traducao += "\tif (!" + $5.label + ") goto " + rotuloFimForReal + ";\n"; 
                $$.traducao += $10.traducao;
                $$.traducao += rotuloIncrementoReal + ":\n"; 
                $$.traducao += $7.traducao;
                $$.traducao += "\tgoto " + rotuloTesteReal + ";\n"; 
                $$.traducao += rotuloFimForReal + ":\n";

                pilhaRotulosProxIteracao.pop();
                pilhaRotulosFimLoop.pop();
            }
            | TK_BREAK FIM_LINHA
            {
                if (pilhaRotulosFimLoop.empty()) {
                    yyerror("Erro semântico: 'break' fora de um laço.");
                }
                $$.traducao = "\tgoto " + pilhaRotulosFimLoop.top() + ";\n";
            }
            | TK_CONTINUE FIM_LINHA
            {
                if (pilhaRotulosProxIteracao.empty()) {
                    yyerror("Erro semântico: 'continue' fora de um laço.");
                }
                $$.traducao = "\tgoto " + pilhaRotulosProxIteracao.top() + ";\n";
            }
            // --- REGRA DE PRINT ATUALIZADA COM A LÓGICA DO SEGUNDO CÓDIGO ---
            | TK_PRINT '(' EXP ')' FIM_LINHA
            {
                if ($3.tipo == "string_literal") {
                    // Lógica do segundo código: aloca, imprime e libera imediatamente.
                    string temp_print_str = insereTemporariasTabelaSimbolos("", "string");
                    int tamanho = tamanho_string($3.traducao); // Usa a função substituída

                    stringstream ss;
                    ss << "\t" << temp_print_str << " = (char*) malloc(" << tamanho << ");\n";
                    ss << "\tstrcpy(" << temp_print_str << ", " << $3.traducao << ");\n";
                    ss << "\tprintf(\"%s\\n\", " << temp_print_str << ");\n";
                    ss << "\tfree(" << temp_print_str << ");\n"; // Liberação imediata
                    $$.traducao = ss.str();

                } else {
                    // Lógica original para outras variáveis (números, char, variáveis string)
                    string formato = "";
                    string tipoVar = pegaTipo($3.tipo);
                    
                    if (tipoVar == "int") formato = "%d";
                    else if (tipoVar == "float") formato = "%f";
                    else if (tipoVar == "char") formato = "%c";
                    else if (tipoVar == "bool") formato = "%d";
                    else if (tipoVar == "string") formato = "%s";
                    else {
                        yyerror("Tipo inválido para 'print': " + $3.tipo);
                    }
                    
                    $$.traducao = $3.traducao + "\tprintf(\"" + formato + "\\n\", " + $3.label + ");\n";
                }
            }
            // --- REGRA DE SCAN (LÓGICA IDÊNTICA EM AMBOS OS CÓDIGOS) ---
            | TK_SCAN '(' TK_ID ')' FIM_LINHA
            {
                TIPO_SIMBOLO varSimbolo;
                if (!verificaTabelaSimbolos($3.label)) {
                    yyerror("Variável '" + $3.label + "' não declarada para 'scan'.");
                } else {
                    varSimbolo = pegaVariavelTabelaSimbolos($3.label);
                }

                if (varSimbolo.tipoVariavel == "string") {
                    stringstream ss;
                    ss << "\tfree(" << varSimbolo.label << ");\n";
                    ss << "\t" << varSimbolo.label << " = (char*) malloc(" << SCAN_BUFFER_SIZE << ");\n";
                    ss << "\tscanf(\"%s\", " << varSimbolo.label << ");\n";
                    
                    variaveisAlocadas.insert(varSimbolo.label);
                    $$.traducao = ss.str();
                } else {
                    string formato = (varSimbolo.tipoVariavel == "int" || varSimbolo.tipoVariavel == "bool") ? "%d" :
                                     (varSimbolo.tipoVariavel == "float") ? "%f" : " %c";
                    string argumentoScan = "&" + varSimbolo.label;
                    
                    $$.traducao = "\tscanf(\"" + formato + "\", " + argumentoScan + ");\n";
                }
            }
            | TK_RETURN EXP FIM_LINHA
            {
                $$.traducao = $2.traducao + "\treturn " + $2.label + ";\n";
            }
            | TK_RETURN EXP
            {
                $$.traducao = $2.traducao + "\treturn " + $2.label + ";\n";
            }
            ;


FOR_INICIA  : DECL { $$.traducao = $1.traducao; }
            | ATR { $$.traducao = $1.traducao; }
            | { $$.traducao = ""; }
            ;
FOR_INCREM  : ATR { $$.traducao = $1.traducao; }
            | EXP { $$.traducao = $1.traducao; }
            | { $$.traducao = ""; }
            ;


DECL        : TK_TIPO TK_ID 
            {
                insereFixasTabelaSimbolos($2.label, $1.label);
                $$.traducao = ""; // A declaração real ocorre no início do código C
            }
            // --- REGRA DE DECLARAÇÃO COM INICIALIZAÇÃO (LÓGICA IDÊNTICA EM AMBOS) ---
            | TK_TIPO TK_ID '=' EXP
            {
                insereFixasTabelaSimbolos($2.label, $1.label);
                TIPO_SIMBOLO varSimbolo = pegaVariavelTabelaSimbolos($2.label);

                string tipoExp = pegaTipo($4.tipo);
                // Tipo de checagem do segundo código (sem char_array)
                if (varSimbolo.tipoVariavel != tipoExp && varSimbolo.tipoVariavel != "string" && $4.tipo != "string_literal") {
                    yyerror("Tipo incompatível na declaração de '" + $2.label + "'.");
                }
                
                if (varSimbolo.tipoVariavel == "string") {
                    string temp_tamanho = insereTemporariasTabelaSimbolos("", "int");
                    stringstream ss;

                    if ($4.tipo == "string_literal") {

                        int tamanho = tamanho_string($4.traducao);
                        ss << "\t" << temp_tamanho << " = " << tamanho << ";\n";
                        ss << "\t" << varSimbolo.label << " = (char*) malloc(" << temp_tamanho << ");\n";
                        ss << "\tstrcpy(" << varSimbolo.label << ", " << $4.traducao << ");\n";
                    } else { // O lado direito é uma variável string
                        ss << $4.traducao;
                        ss << "\t" << temp_tamanho << " = meu_strlen(" << $4.label << ") + 1;\n";
                        ss << "\t" << varSimbolo.label << " = (char*) malloc(" << temp_tamanho << ");\n";
                        ss << "\tstrcpy(" << varSimbolo.label << ", " << $4.label << ");\n";
                    }
                    $$.traducao = ss.str();
                    variaveisAlocadas.insert(varSimbolo.label);
                } else {
                    $$.traducao = $4.traducao + "\t" + varSimbolo.label + " = " + $4.label + ";\n";
                }
            }
            | TK_TIPO TK_ID '[' TK_INT ']' '[' TK_INT ']'
            {
                string tipo = pegaTipo($1.label);
                int tamanho1 = stoi($4.label);
                int tamanho2 = stoi($7.label);
                insereFixasTabelaSimbolos($2.label, $1.label, true, tamanho1, tamanho2);
                $$.traducao = "";
            }
            | TK_TIPO TK_ID '[' TK_INT ']'
            {
                string tipo = pegaTipo($1.label);
                int tamanho = stoi($4.label);
                insereFixasTabelaSimbolos($2.label, $1.label, true, tamanho);
                $$.traducao = "";
            }
            ;

ATR         : TK_ID '=' EXP
            {
                TIPO_SIMBOLO varEsquerda = pegaVariavelTabelaSimbolos($1.label);
                string tipoExp = pegaTipo($3.tipo);

                // Tipo de checagem do segundo código (sem char_array)
                if (varEsquerda.tipoVariavel != tipoExp && varEsquerda.tipoVariavel != "string" && $3.tipo != "string_literal") {
                    yyerror("Tipo incompatível na atribuição para '" + $1.label + "'.");
                }

                $$.label = varEsquerda.label;

                // --- LÓGICA DE ATRIBUIÇÃO DE STRING (IDÊNTICA EM AMBOS) ---
                if (varEsquerda.tipoVariavel == "string") {
                    string temp_tamanho = insereTemporariasTabelaSimbolos("", "int");
                    stringstream ss;

                    ss << "\tfree(" << varEsquerda.label << ");\n";

                    if ($3.tipo == "string_literal") {
                        int tamanho = tamanho_string($3.traducao);
                        ss << "\t" << temp_tamanho << " = " << tamanho << ";\n";
                        ss << "\t" << varEsquerda.label << " = (char*) malloc(" << temp_tamanho << ");\n";
                        ss << "\tstrcpy(" << varEsquerda.label << ", " << $3.traducao << ");\n";
                    } else { // O lado direito é outra variável string
                        ss << $3.traducao;
                        ss << "\t" << temp_tamanho << " = meu_strlen(" << $3.label << ") + 1;\n";
                        ss << "\t" << varEsquerda.label << " = (char*) malloc(" << temp_tamanho << ");\n";
                        ss << "\tstrcpy(" << varEsquerda.label << ", " << $3.label << ");\n";
                    }
                    $$.traducao = ss.str();
                    variaveisAlocadas.insert(varEsquerda.label); 
                } else {
                    $$.traducao = $3.traducao + "\t" + varEsquerda.label + " = " + $3.label + ";\n";
                }
            }
            | TK_ID TK_MAIS_IGUAL EXP
            {
                TIPO_SIMBOLO varEsquerda = pegaVariavelTabelaSimbolos($1.label);
                string tipoResultado = infereTipo(varEsquerda.tipoVariavel, $3.tipo);
                if (tipoResultado != varEsquerda.tipoVariavel && varEsquerda.tipoVariavel != "float") {
                    yyerror("Erro de tipo em '+=': Nao e possivel atribuir um " + tipoResultado + " a um " + varEsquerda.tipoVariavel);
                }

                string temp_valor_esq = insereTemporariasTabelaSimbolos("", varEsquerda.tipoVariavel);
                string temp_resultado = insereTemporariasTabelaSimbolos("", tipoResultado);
                stringstream ss;
                ss << $3.traducao;
                ss << "\t" << temp_valor_esq << " = " << varEsquerda.label << ";\n";
                ss << "\t" << temp_resultado << " = " << temp_valor_esq << " + " << $3.label << ";\n";
                ss << "\t" << varEsquerda.label << " = " << temp_resultado << ";\n";
                $$.traducao = ss.str();
                $$.label = varEsquerda.label;
                $$.tipo = varEsquerda.tipoVariavel;
            }
            | TK_ID TK_MENOS_IGUAL EXP
            {
                TIPO_SIMBOLO varEsquerda = pegaVariavelTabelaSimbolos($1.label);
                string tipoResultado = infereTipo(varEsquerda.tipoVariavel, $3.tipo);
                if (tipoResultado != varEsquerda.tipoVariavel && varEsquerda.tipoVariavel != "float") { yyerror("Erro de tipo em '-='."); }

                string temp_valor_esq = insereTemporariasTabelaSimbolos("", varEsquerda.tipoVariavel);
                string temp_resultado = insereTemporariasTabelaSimbolos("", tipoResultado);
                stringstream ss;
                ss << $3.traducao;
                ss << "\t" << temp_valor_esq << " = " << varEsquerda.label << ";\n";
                ss << "\t" << temp_resultado << " = " << temp_valor_esq << " - " << $3.label << ";\n";
                ss << "\t" << varEsquerda.label << " = " << temp_resultado << ";\n";
                $$.traducao = ss.str();
                $$.label = varEsquerda.label;
                $$.tipo = varEsquerda.tipoVariavel;
            }
            | TK_ID TK_MULT_IGUAL EXP
            {
                TIPO_SIMBOLO varEsquerda = pegaVariavelTabelaSimbolos($1.label);
                string tipoResultado = infereTipo(varEsquerda.tipoVariavel, $3.tipo);
                if (tipoResultado != varEsquerda.tipoVariavel && varEsquerda.tipoVariavel != "float") { yyerror("Erro de tipo em '*='."); }

                string temp_valor_esq = insereTemporariasTabelaSimbolos("", varEsquerda.tipoVariavel);
                string temp_resultado = insereTemporariasTabelaSimbolos("", tipoResultado);
                stringstream ss;
                ss << $3.traducao;
                ss << "\t" << temp_valor_esq << " = " << varEsquerda.label << ";\n";
                ss << "\t" << temp_resultado << " = " << temp_valor_esq << " * " << $3.label << ";\n";
                ss << "\t" << varEsquerda.label << " = " << temp_resultado << ";\n";
                $$.traducao = ss.str();
                $$.label = varEsquerda.label;
                $$.tipo = varEsquerda.tipoVariavel;
            }
            | TK_ID TK_DIV_IGUAL EXP
            {
                TIPO_SIMBOLO varEsquerda = pegaVariavelTabelaSimbolos($1.label);
                string tipoResultado = infereTipo(varEsquerda.tipoVariavel, $3.tipo);
                if (tipoResultado != varEsquerda.tipoVariavel && varEsquerda.tipoVariavel != "float") { yyerror("Erro de tipo em '/='."); }

                string temp_valor_esq = insereTemporariasTabelaSimbolos("", varEsquerda.tipoVariavel);
                string temp_resultado = insereTemporariasTabelaSimbolos("", tipoResultado);
                stringstream ss;
                ss << $3.traducao;
                ss << "\t" << temp_valor_esq << " = " << varEsquerda.label << ";\n";
                ss << "\t" << temp_resultado << " = " << temp_valor_esq << " / " << $3.label << ";\n";
                ss << "\t" << varEsquerda.label << " = " << temp_resultado << ";\n";
                $$.traducao = ss.str();
                $$.label = varEsquerda.label;
                $$.tipo = varEsquerda.tipoVariavel;
            }
            | TK_ID '[' EXP ']' '=' EXP
            {
                TIPO_SIMBOLO temp = pegaVariavelTabelaSimbolos($1.label);
                if (!temp.isArray) yyerror("Variável '" + $1.label + "' não é um vetor.");
                if ($3.tipo != "int") yyerror("Índice de vetor deve ser inteiro.");
                if (temp.tipoVariavel != pegaTipo($6.tipo)) yyerror("Tipo incompatível ao atribuir em vetor.");

                $$.label = temp.label;
                $$.traducao = $3.traducao + $6.traducao + "\t" + temp.label + "[" + $3.label + "] = " + $6.label + ";\n";
            }
            | TK_ID '[' EXP ']' '[' EXP ']' '=' EXP
            {
                TIPO_SIMBOLO mat = pegaVariavelTabelaSimbolos($1.label);
                if (!mat.isArray || mat.arraySize2 == 0) yyerror("'" + $1.label + "' não é matriz 2D.");
                if ($3.tipo != "int" || $6.tipo != "int") yyerror("Índices de matriz devem ser inteiros.");
                if (mat.tipoVariavel != pegaTipo($9.tipo)) yyerror("Tipo incompatível ao atribuir em matriz.");
                
                string tempMult = insereTemporariasTabelaSimbolos("temp", "int");
                string tempIdx  = insereTemporariasTabelaSimbolos("temp", "int");
                $$.traducao  = $3.traducao + $6.traducao +
                                 "\t" + tempMult + " = " + $3.label + " * " + to_string(mat.arraySize2) + ";\n" +
                                 "\t" + tempIdx  + " = " + tempMult + " + " + $6.label + ";\n" +
                                 $9.traducao +
                                 "\t" + mat.label + "[" + tempIdx + "] = " + $9.label + ";\n";
            }
            | TK_ID '=' TK_ID '[' EXP ']' '[' EXP ']'
            {
                TIPO_SIMBOLO mat = pegaVariavelTabelaSimbolos($3.label);
                if (!mat.isArray || mat.arraySize2 == 0) yyerror("'" + $3.label + "' não é matriz 2D.");
                TIPO_SIMBOLO destino = pegaVariavelTabelaSimbolos($1.label);
                if (destino.tipoVariavel != mat.tipoVariavel) yyerror("Tipos incompatíveis.");
                if ($5.tipo != "int" || $8.tipo != "int") yyerror("Índices da matriz devem ser inteiros.");
                
                string tempMult = insereTemporariasTabelaSimbolos("temp", "int");
                string tempIdx  = insereTemporariasTabelaSimbolos("temp", "int");
                $$.traducao  = $5.traducao + $8.traducao +
                                 "\t" + tempMult + " = " + $5.label + " * " + to_string(mat.arraySize2) + ";\n" +
                                 "\t" + tempIdx  + " = " + tempMult + " + " + $8.label + ";\n" +
                                 "\t" + destino.label + " = " + mat.label + "[" + tempIdx + "];\n";
                $$.label = $1.label;
                $$.tipo  = destino.tipoVariavel;
            }
            | TK_ID '=' TK_ID '[' EXP ']'
            {
                TIPO_SIMBOLO vet = pegaVariavelTabelaSimbolos($3.label);
                if (!vet.isArray || vet.arraySize2 != 0) yyerror("'" + $3.label + "' não é vetor 1D.");
                TIPO_SIMBOLO destino = pegaVariavelTabelaSimbolos($1.label);
                if (destino.tipoVariavel != vet.tipoVariavel) yyerror("Tipos incompatíveis.");
                if ($5.tipo != "int") yyerror("Índice do vetor deve ser inteiro.");

                $$.traducao  = $5.traducao + "\t" + $1.label + " = " + vet.label + "[" + $5.label + "];\n";
                $$.label = destino.label;
                $$.tipo  = destino.tipoVariavel;
            }
            ;   

EXP         : EXP '+' TERMO 
            {   
                $$.tipo = infereTipo($1.tipo, $3.tipo);
                $$.traducao = $1.traducao + $3.traducao;

                // --- LÓGICA DE CONCATENAÇÃO DE STRING (IDÊNTICA EM AMBOS OS CÓDIGOS) ---
                if ($$.tipo == "string") {
                    $$.label = insereTemporariasTabelaSimbolos("", "string");
                    string temp_len1 = insereTemporariasTabelaSimbolos("", "int");
                    string temp_len2 = insereTemporariasTabelaSimbolos("", "int");
                    string temp_total_len = insereTemporariasTabelaSimbolos("", "int");
                    stringstream ss;

                    if ($1.tipo == "string_literal") {
                        ss << "\t" << temp_len1 << " = " << tamanho_string($1.label) - 1 << ";\n";
                    } else {
                        ss << "\t" << temp_len1 << " = meu_strlen(" << $1.label << ");\n";
                    }

                    if ($3.tipo == "string_literal") {
                        ss << "\t" << temp_len2 << " = " << tamanho_string($3.label) - 1 << ";\n";
                    } else {
                        ss << "\t" << temp_len2 << " = meu_strlen(" << $3.label << ");\n";
                    }

                    ss << "\t" << temp_total_len << " = " << temp_len1 << " + " << temp_len2 << " + 1;\n";
                    ss << "\t" << $$.label << " = (char*) malloc(" << temp_total_len << ");\n";
                    ss << "\tstrcpy(" << $$.label << ", " << $1.label << ");\n";
                    ss << "\tstrcat(" << $$.label << ", " << $3.label << ");\n";
                    $$.traducao += ss.str();
                    variaveisAlocadas.insert($$.label);
                } 
                // Lógica original para números
                else {
                    $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                    if($1.tipo == "int" && $3.tipo == "float") {
                        string temporario = insereTemporariasTabelaSimbolos("","float");
                        $$.traducao += "\t" + temporario + " = (float) " + $1.label + ";\n" +
                                        "\t" + $$.label + " = " + temporario + " + " + $3.label + ";\n";
                    } else if($1.tipo == "float" && $3.tipo == "int") {
                        string temporario = insereTemporariasTabelaSimbolos("","float");
                        $$.traducao += "\t" + temporario + " = (float) " + $3.label + ";\n" +
                                        "\t" + $$.label + " = " + $1.label + " + " + temporario + ";\n";
                    } else if($1.tipo == "bool" || $3.tipo == "bool") {
                        yyerror("[ERRO] Operação '+' inválida entre tipos " + $1.tipo + " e " + $3.tipo);
                    } else {
                        $$.traducao += "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
                    }
                }
            }
            | EXP '-' TERMO 
            {   
                $$.tipo = infereTipo($1.tipo, $3.tipo);
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao;
                
                if($1.tipo == "int" && $3.tipo == "float") {
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    $$.traducao += "\t" + temporario + " = (float) " + $1.label + ";\n" +
                                    "\t" + $$.label + " = " + temporario + " - " + $3.label + ";\n"; 
                } else if($1.tipo == "float" && $3.tipo == "int") {
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    $$.traducao += "\t" + temporario + " = (float) " + $3.label + ";\n" + 
                                    "\t" + $$.label + " = " + $1.label + " - " + temporario + ";\n"; 
                } else if($1.tipo == "bool" || $3.tipo == "bool"|| $1.tipo == "string" || $3.tipo == "string") {
                    yyerror("[ERRO] Operação '-' inválida entre tipos " + $1.tipo + " e " + $3.tipo);
                } else {
                    $$.traducao += "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
                }
            }
            | EXP '>' TERMO 
            {   
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                if($1.tipo == "bool" || $3.tipo == "bool" || $1.tipo == "string" || $3.tipo == "string") yyerror("Operandos inválidos\n");
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " > " + $3.label + ";\n";
            }
            | EXP '<' TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                if($1.tipo == "bool" || $3.tipo == "bool" || $1.tipo == "string" || $3.tipo == "string") yyerror("Operandos inválidos\n");
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " < " + $3.label + ";\n";
            }
            | EXP TK_MAIOR_IGUAL TERMO
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                if($1.tipo == "bool" || $3.tipo == "bool" || $1.tipo == "string" || $3.tipo == "string") yyerror("Operandos inválidos\n");
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " >= " + $3.label + ";\n";
            }
            | EXP TK_MENOR_IGUAL TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                if($1.tipo == "bool" || $3.tipo == "bool" || $1.tipo == "string" || $3.tipo == "string") yyerror("Operandos inválidos\n");
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " <= " + $3.label + ";\n";
            }
            | EXP TK_DIFERENTE TERMO
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                if($1.tipo == "bool" || $3.tipo == "bool" || $1.tipo == "string" || $3.tipo == "string") yyerror("Operandos inválidos\n");
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " != " + $3.label + ";\n";
            }
            | EXP TK_IGUAL TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                if($1.tipo == "bool" || $3.tipo == "bool" || $1.tipo == "string" || $3.tipo == "string") yyerror("Operandos inválidos\n");
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " == " + $3.label + ";\n";
            }
            | EXP TK_E_LOGICO TERMO
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                if($1.tipo != "bool" || $3.tipo != "bool") yyerror("Operandos inválidos\n");
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " && " + $3.label + ";\n";   
            }
            | EXP TK_OU_LOGICO TERMO
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                if($1.tipo != "bool" || $3.tipo != "bool") yyerror("Operandos inválidos\n");
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " || " + $3.label + ";\n";   
            }
            | TERMO
            { $$ = $1; }
            ;

TERMO       : TERMO '*' POTENCIA
            {   
                $$.tipo = infereTipo($1.tipo, $3.tipo);
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao;

                if($1.tipo == "int" && $3.tipo == "float") {
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    $$.traducao += "\t" + temporario + " = (float) " + $1.label + ";\n" +
                                    "\t" + $$.label + " = " + temporario + " * " + $3.label + ";\n"; 
                } else if($1.tipo == "float" && $3.tipo == "int") {
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    $$.traducao += "\t" + temporario + " = (float) " + $3.label + ";\n" + 
                                    "\t" + $$.label + " = " + $1.label + " * " + temporario + ";\n"; 
                } else if($1.tipo == "bool" || $3.tipo == "bool" || $1.tipo == "string" || $3.tipo == "string") {
                    yyerror("[ERRO] Operação '*' inválida entre tipos " + $1.tipo + " e " + $3.tipo);
                } else {
                    $$.traducao += "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
                }
            }
            | TERMO '/' POTENCIA
            { 
                $$.tipo = infereTipo($1.tipo, $3.tipo);
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao;

                if($1.tipo == "int" && $3.tipo == "float") {
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    $$.traducao += "\t" + temporario + " = (float) " + $1.label + ";\n" +
                                    "\t" + $$.label + " = " + temporario + " / " + $3.label + ";\n"; 
                } else if($1.tipo == "float" && $3.tipo == "int") {
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    $$.traducao += "\t" + temporario + " = (float) " + $3.label + ";\n" + 
                                    "\t" + $$.label + " = " + $1.label + " / " + temporario + ";\n"; 
                } else if($1.tipo == "bool" || $3.tipo == "bool" || $1.tipo == "string" || $3.tipo == "string") {
                    yyerror("[ERRO] Operação '/' inválida entre tipos " + $1.tipo + " e " + $3.tipo);
                } else {
                    $$.traducao += "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
                }
            }
            | POTENCIA
            { $$ = $1; }
            ;

FATOR       : TK_ID '(' LISTA_ARGS ')'
            {
                string nomeFunc = $1.label;
                
                if (!tabelaFuncoes.count(nomeFunc)) {
                    yyerror("Função '" + nomeFunc + "' não foi declarada.");
                }

                TIPO_FUNCAO infoFunc = tabelaFuncoes[nomeFunc];
                string tipoRetorno = infoFunc.tipoRetorno;
                
                $$.label = insereTemporariasTabelaSimbolos("", tipoRetorno);
                $$.tipo = tipoRetorno;
                $$.traducao = $3.traducao + "\t" + $$.label + " = " + nomeFunc + "(" + $3.label + ");\n";
            }
            | '-' FATOR
            {
                if ($2.tipo != "int" && $2.tipo != "float") {
                    yyerror("Operador '-' unario so pode ser aplicado a tipos numericos (int, float).");
                }
                $$.tipo = $2.tipo; 
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                $$.traducao = $2.traducao + "\t" + $$.label + " = -" + $2.label + ";\n";
            }
            | TK_INCREMENTO TK_ID
            {
                TIPO_SIMBOLO var = pegaVariavelTabelaSimbolos($2.label);
                if (var.tipoVariavel != "int" && var.tipoVariavel != "float") yyerror("Operador '++' so pode ser aplicado a variaveis numericas.");

                $$.tipo = var.tipoVariavel;
                string temp_um = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                string temp_valor_var = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                string temp_soma = insereTemporariasTabelaSimbolos("", var.tipoVariavel);

                stringstream ss;
                ss << "\t" << temp_um << " = 1;\n";
                ss << "\t" << temp_valor_var << " = " << var.label << ";\n";
                ss << "\t" << temp_soma << " = " << temp_valor_var << " + " << temp_um << ";\n";
                ss << "\t" << var.label << " = " << temp_soma << ";\n";
                $$.traducao = ss.str();
                $$.label = var.label;
            }
            | TK_ID TK_INCREMENTO
            {
                TIPO_SIMBOLO var = pegaVariavelTabelaSimbolos($1.label);
                if (var.tipoVariavel != "int" && var.tipoVariavel != "float") yyerror("Operador '++' so pode ser aplicado a variaveis numericas.");

                $$.tipo = var.tipoVariavel;
                string temp_retorno = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                string temp_um = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                string temp_soma = insereTemporariasTabelaSimbolos("", var.tipoVariavel);

                stringstream ss;
                ss << "\t" << temp_retorno << " = " << var.label << ";\n";
                ss << "\t" << temp_um << " = 1;\n";
                ss << "\t" << temp_soma << " = " << temp_retorno << " + " << temp_um << ";\n";
                ss << "\t" << var.label << " = " << temp_soma << ";\n";
                $$.traducao = ss.str();
                $$.label = temp_retorno;
            }
            | TK_DECREMENTO TK_ID
            {
                TIPO_SIMBOLO var = pegaVariavelTabelaSimbolos($2.label);
                if (var.tipoVariavel != "int" && var.tipoVariavel != "float") yyerror("Operador '--' so pode ser aplicado a variaveis numericas.");
                
                $$.tipo = var.tipoVariavel;
                string temp_um = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                string temp_valor_var = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                string temp_sub = insereTemporariasTabelaSimbolos("", var.tipoVariavel);

                stringstream ss;
                ss << "\t" << temp_um << " = 1;\n";
                ss << "\t" << temp_valor_var << " = " << var.label << ";\n";
                ss << "\t" << temp_sub << " = " << temp_valor_var << " - " << temp_um << ";\n";
                ss << "\t" << var.label << " = " << temp_sub << ";\n";
                $$.traducao = ss.str();
                $$.label = var.label;
            }
            | TK_ID TK_DECREMENTO
            {
                TIPO_SIMBOLO var = pegaVariavelTabelaSimbolos($1.label);
                if (var.tipoVariavel != "int" && var.tipoVariavel != "float") yyerror("Operador '--' so pode ser aplicado a variaveis numericas.");

                $$.tipo = var.tipoVariavel;
                string temp_retorno = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                string temp_um = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                string temp_sub = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                
                stringstream ss;
                ss << "\t" << temp_retorno << " = " << var.label << ";\n";
                ss << "\t" << temp_um << " = 1;\n";
                ss << "\t" << temp_sub << " = " << temp_retorno << " - " << temp_um << ";\n";
                ss << "\t" << var.label << " = " << temp_sub << ";\n";
                $$.traducao = ss.str();
                $$.label = temp_retorno;
            }
            |'(' EXP ')' 
            { $$ = $2; }
            | '(' TK_TIPO ')' FATOR
            {   
                $$.label = insereTemporariasTabelaSimbolos("", $2.label);
                $$.tipo = $2.label;
                $$.traducao = $4.traducao + "\t" + $$.label + " = (" + pegaTipo($2.label) + ") " + $4.label + ";\n";
            }
            | TK_ID
            {
                if (!verificaTabelaSimbolos($1.label)) {
                    yyerror("Variável não declarada: '" + $1.label + "'");
                }
                TIPO_SIMBOLO simbolo = pegaVariavelTabelaSimbolos($1.label);

                if (simbolo.isParam) {
                    $$.label = simbolo.nomeVariavel;
                } else {
                    $$.label = simbolo.label;
                }

                $$.tipo = simbolo.tipoVariavel;
                $$.traducao = "";

                if (simbolo.isArray) {
                    yyerror("Acesso inválido: vetor/matriz '" + simbolo.nomeVariavel + "' usado sem índice.");
                }
            }
            | TK_NEGACAO TK_ID
            {
                $$.tipo = "bool";
                TIPO_SIMBOLO temp = pegaVariavelTabelaSimbolos($2.label);
                if("bool" != temp.tipoVariavel) yyerror("Operação de negação inválida para o tipo da variável.");
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                $$.traducao = "\t" + $$.label + " = !" + temp.label + ";\n";
            }
            | TK_INT
            {   
                $$.label = insereTemporariasTabelaSimbolos("", "int");
                $$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
                $$.tipo = "int"; 
            }
            | TK_FLOAT
            {   
                $$.label = insereTemporariasTabelaSimbolos("", "float");
                $$.traducao = "\t" + $$.label + " = " + $1.label + ";\n"; 
                $$.tipo = "float"; 
            }
            | TK_BOOLEAN
            {
                $$.label = insereTemporariasTabelaSimbolos("", "bool");
                string valor = pegaBooleano($1.label);
                if(valor == "error") yyerror("Valor booleano inválido!");
                $$.traducao = "\t" + $$.label + " = " + valor + ";\n";
                $$.tipo = "bool"; 
            }
            | TK_CHAR
            {
                $$.label = insereTemporariasTabelaSimbolos("", "char");
                $$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
                $$.tipo = "char"; 
            }
            // --- REGRA AJUSTADA PARA LITERAL DE STRING ---
            | TK_STRING
            {
                // Apenas passa o literal (ex: "meu texto") para cima na árvore
                // e marca o tipo como 'string_literal' para que outras regras saibam
                // que não se trata de uma variável, mas de um valor constante.
                $$.label = $1.label;
                $$.traducao = $1.traducao;
                $$.tipo = "string_literal"; 
            }
            | TK_ID '[' EXP ']' {
                TIPO_SIMBOLO vet = pegaVariavelTabelaSimbolos($1.label);
                if (!vet.isArray || vet.arraySize2 != 0) yyerror("'" + $1.label + "' não é vetor 1D.");
                if ($3.tipo != "int") yyerror("Índice do vetor deve ser inteiro.");

                string temp = insereTemporariasTabelaSimbolos("", vet.tipoVariavel);
                $$.traducao = $3.traducao + "\t" + temp + " = " + vet.label + "[" + $3.label + "];\n";
                $$.label = temp;
                $$.tipo = vet.tipoVariavel;
            }
            | TK_ID '[' EXP ']' '[' EXP ']' {
                TIPO_SIMBOLO mat = pegaVariavelTabelaSimbolos($1.label);
                if (!mat.isArray || mat.arraySize2 == 0) yyerror("'" + $1.label + "' não é matriz 2D.");
                if ($3.tipo != "int" || $6.tipo != "int") yyerror("Índices da matriz devem ser inteiros.");

                string tempMult = insereTemporariasTabelaSimbolos("", "int");
                string tempIdx  = insereTemporariasTabelaSimbolos("", "int");
                string tempRes  = insereTemporariasTabelaSimbolos("", mat.tipoVariavel);
                $$.traducao = $3.traducao + $6.traducao +
                                 "\t" + tempMult + " = " + $3.label + " * " + to_string(mat.arraySize2) + ";\n" +
                                 "\t" + tempIdx  + " = " + tempMult + " + " + $6.label + ";\n" +
                                 "\t" + tempRes  + " = " + mat.label + "[" + tempIdx + "];\n";
                $$.label = tempRes;
                $$.tipo = mat.tipoVariavel;
            }
            ;

LISTA_ARGS
    : EXP ',' LISTA_ARGS
        { 
            $$.traducao = $1.traducao + $3.traducao; 
            $$.label = $1.label + ", " + $3.label;
        }
    | EXP
        { $$ = $1; }
    | /* vazio */
        {
            $$.traducao = "";
            $$.label = "";
        }
;

POTENCIA
    : FATOR TK_POTENCIA POTENCIA  // Associatividade à direita para 'a ** b ** c'
        {
            // Verificação: Nossa função helper espera um expoente inteiro.
            if ($3.tipo != "int") {
                yyerror("Potenciação com expoente não-inteiro não é suportada.");
            }

            string base = $1.label;
            string expoente = $3.label;

            // Junta o código de preparação da base e do expoente.
            string traducao_preparacao = $1.traducao + $3.traducao;

            // A função helper espera uma base float, então convertemos se for int.
            if ($1.tipo == "int") {
                string temp_base = insereTemporariasTabelaSimbolos("", "float");
                traducao_preparacao += "\t" + temp_base + " = (float) " + base + ";\n";
                base = temp_base;
            }

            $$.tipo = "float"; // Nossa função helper sempre retorna float.
            $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);

            // A tradução agora é apenas uma chamada para a função helper
            $$.traducao = traducao_preparacao +
                         "\t" + $$.label + " = potencia_helper(" + base + ", " + expoente + ");\n";
        }
    | FATOR
        { $$ = $1; } // Se não houver '**', apenas repassa os atributos do FATOR.
;
%%

#include "lex.yy.c"

int yyparse();

// --- FUNÇÃO `tamanho_string` SUBSTITUÍDA PELA DO SEGUNDO CÓDIGO ---
int tamanho_string(string texto){ 
    // O texto vem com aspas, ex: "abc". O tamanho é 5 ('"', 'a', 'b', 'c', '"').
    // O tamanho real da string é 3 ('a', 'b', 'c').
    // Precisamos alocar 4 bytes (para 'a', 'b', 'c', '\0').
    // Então, o tamanho do texto do token - 2 (aspas) + 1 (null terminator) = tamanho - 1.
    return texto.length() - 1;
}

string novo_rotulo() {
    return "L" + to_string(contador_rotulos++);
}

string geraNomeTemp(string tipo)
{
    qntdVariaveisTemp++;
    string label = "T" + to_string(qntdVariaveisTemp);
    string tipo_real = "null";

    if(tipo == "nmr" || tipo == "int") tipo_real = "int";
    else if(tipo == "ncv" || tipo == "float") tipo_real = "float";
    else if(tipo == "pp" || tipo == "bool") tipo_real = "int"; // Booleanos são traduzidos para int
    else if(tipo == "letra" || tipo == "char") tipo_real = "char";
    else if(tipo == "falada" || tipo == "string" || tipo == "string_literal" || tipo == "char_array") tipo_real = "string";
    
    temporarias.insert({label, tipo_real});
    return label; 
}

string insereTemporariasTabelaSimbolos(string nome, string tipo)
{   
    if (pilhaTabelasSimbolos.empty()) {
        yyerror("Erro de lógica: Tentou gerar temporária sem um escopo ativo.");
        return "";
    }
    map<string, TIPO_SIMBOLO>& escopoAtual = pilhaTabelasSimbolos.back();
    
    TIPO_SIMBOLO temp;
    temp.nomeVariavel = geraNomeTemp(tipo);
    temp.tipoVariavel = pegaTipo(tipo);
    temp.label = temp.nomeVariavel;

    escopoAtual[temp.nomeVariavel] = temp;
    todosOsSimbolos.push_back(temp);
    if(debug) cout << "[DEBUG] Inserindo TEMPORARIA na tabela: " << temp.nomeVariavel << " (Tipo: " << temp.tipoVariavel << ")\n";
    return temp.label;
}

void insereFixasTabelaSimbolos(string nome, string tipo, bool ehArray, int tamanhoArray, int tamanhoArray2, bool ehParam)
{   
    if (pilhaTabelasSimbolos.empty()) {
        yyerror("Erro de lógica: Tentou declarar variável sem um escopo ativo.");
        return;
    }

    map<string, TIPO_SIMBOLO>& escopoAtual = pilhaTabelasSimbolos.back();

    if (escopoAtual.count(nome)) {
        yyerror("Erro: Variável '" + nome + "' já declarada neste escopo.");
        return;
    }

    if (debug) cout << "[DEBUG] Inserindo FIXA na tabela: " << nome << " (Tipo: " << tipo << ")\n";

    TIPO_SIMBOLO temp;
    temp.nomeVariavel = nome;
    temp.tipoVariavel = pegaTipo(tipo);
    temp.label = geraNomeTemp(tipo);
    temp.isArray = ehArray;
    temp.arraySize = tamanhoArray;
    temp.arraySize2 = tamanhoArray2;
    temp.isParam = ehParam; // Campo preservado do primeiro código

    escopoAtual[nome] = temp;
    todosOsSimbolos.push_back(temp); // <-- ADICIONE ESTA LINHA
}

bool verificaTabelaSimbolos(string nome)
{
    for (int i = pilhaTabelasSimbolos.size() - 1; i >= 0; --i) {
        if (pilhaTabelasSimbolos[i].count(nome)) { 
            return true; 
        }
    }
    return false;
}

TIPO_SIMBOLO pegaVariavelTabelaSimbolos(string nome)
{
    for (int i = pilhaTabelasSimbolos.size() - 1; i >= 0; --i) {
        if (pilhaTabelasSimbolos[i].count(nome)) {
            return pilhaTabelasSimbolos[i][nome];
        }
    }
    yyerror("Variável '" + nome + "' não encontrada.");
    return {}; // Retorno para evitar warnings
}

void printTabelaSimbolos()
{
    if (!debug) return;
    cout << "\n--- Tabela de Simbolos (Escopos) ---\n";
    for (size_t i = 0; i < pilhaTabelasSimbolos.size(); ++i) {
        cout << "Escopo " << i << ":\n";
        for (const auto& pair : pilhaTabelasSimbolos[i]) {
            const TIPO_SIMBOLO& simbolo = pair.second;
            cout << "  Nome: " << simbolo.nomeVariavel
                 << ", Tipo: " << simbolo.tipoVariavel
                 << ", Label: " << simbolo.label << endl;
        }
    }
    cout << "-----------------------------------\n";
}

string pegaTipo(string tipo) 
{
    if(tipo == "nmr" || tipo == "int") return "int";
    if(tipo == "ncv" || tipo == "float") return "float";
    if(tipo == "letra" || tipo == "char") return "char";
    if(tipo == "pp" || tipo == "bool") return "bool";
    if(tipo == "falada" || tipo == "string" || tipo == "string_literal" || tipo == "char_array") return "string";
    return "null";
}

// --- FUNÇÃO `infereTipo` SUBSTITUÍDA PELA DO SEGUNDO CÓDIGO ---
string infereTipo(string tipo1, string tipo2)
{
    if(debug) cout << "[DEBUG] Inferindo tipo entre: " << tipo1 << " e " << tipo2 << endl;

    string t1 = pegaTipo(tipo1);
    string t2 = pegaTipo(tipo2);

    // Se ambos são strings, o resultado é uma string
    if (t1 == "string" && t2 == "string") {
        return "string";
    }

    // Lógica para números (pode ser ajustada para ser mais robusta)
    if(t1 == "float" || t2 == "float") return "float";
    if(t1 == "int" && t2 == "int") return "int";
    
    yyerror("Operação com tipos incompatíveis: " + tipo1 + " e " + tipo2);
    return "null"; // Retorno de erro
}

string pegaBooleano(string valor)
{
    if(valor == "reto") return "true";
    if(valor == "torto") return "false";
    return "error";
}

void entraEscopo()
{
    pilhaTabelasSimbolos.push_back({});
    if (debug) cout << "[DEBUG] Entrou em um novo escopo. Tamanho da pilha: " << pilhaTabelasSimbolos.size() << endl;
}

void saiEscopo()
{
    if (!pilhaTabelasSimbolos.empty()) {
        pilhaTabelasSimbolos.pop_back(); 
        if (debug) cout << "[DEBUG] Saiu do escopo atual. Tamanho da pilha: " << pilhaTabelasSimbolos.size() << endl;
    } else {
        yyerror("Erro de lógica: Tentou sair de um escopo vazio.");
    }
}

int main( int argc, char* argv[] )
{   
    yyparse();
    return 0;
}

void yyerror( string MSG )
{
    cout << "Erro na linha " << yylinha << ": "<< MSG << endl;
    exit (0);
}