%{
#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <set>

#define YYSTYPE atributos

using namespace std;

int qntdVariaveisTemp = 0;
int contador_rotulos = 0;
#define SCAN_BUFFER_SIZE 1024

stack<string> pilhaRotulosFimLoop;
stack<string> pilhaRotulosProxIteracao;
set<string> variaveisAlocadas;

struct atributos 
{
    string label;
    string traducao;
    string tipo;
    int tamanho;
};

typedef struct
{
    string nomeVariavel;
    string tipoVariavel;
    string label;

    bool isArray = false;
    int arraySize = 0;
    int arraySize2 = 0;

   int getTamanhoTotal() const {
        return arraySize * (arraySize2 > 0 ? arraySize2 : 1);
    }

} TIPO_SIMBOLO;

int yylex(void);
void yyerror(string);

set<pair<string,string>> temporarias;
vector<map<string, TIPO_SIMBOLO>> pilhaTabelasSimbolos;
stack<pair<string, string>> pilhaExprSwitch;

bool verificaTabelaSimbolos(string nome);
TIPO_SIMBOLO pegaVariavelTabelaSimbolos(string nome);
void printTabelaSimbolos();
void entraEscopo();
void saiEscopo();

void insereFixasTabelaSimbolos(string nome, string tipo,bool ehArray = false, int tamanhoArray = 0,int tamanhoArray2 = 0);
string insereTemporariasTabelaSimbolos(string nome, string tipo);

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

%token TK_TIPO TK_ID
%token TK_INT TK_FLOAT TK_BOOLEAN TK_CHAR TK_STRING
%token TK_MAIOR_IGUAL TK_MENOR_IGUAL TK_DIFERENTE TK_IGUAL TK_E_LOGICO TK_OU_LOGICO TK_NEGACAO
%token TK_IF TK_ELSE TK_WHILE TK_DO TK_FOR TK_IN TK_SWITCH TK_CASE TK_BREAK TK_DEFAULT TK_CONTINUE
%token TK_PRINT TK_SCAN
%token FIM_LINHA

%start START


%%

START
    : { entraEscopo(); } CODIGO
    {
        string cabecalho = "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\n#define true 1\n#define false 0\n\n";
        string declaracoes = "";

        for (auto i : temporarias) {
            string label = i.first;
            string tipo = i.second;

            if (tipo == "string" || tipo == "char_array") {
                declaracoes += "\tchar* " + label + " = NULL;\n";
            } else if (tipo != "null") {
                declaracoes += "\t" + tipo + " " + label + ";\n";
            }
        }
        
        string corpoCodigo = $2.traducao;

        string frees = "";
        if (!variaveisAlocadas.empty()) {
            for (const auto& varLabel : variaveisAlocadas) {
                frees += "\tfree(" + varLabel + ");\n";
            }
        }

        cout << cabecalho;
        cout << "int main() {\n";
        cout << declaracoes << "\n";
        cout << corpoCodigo;
        cout << frees;
        cout << "\n\treturn 0;\n";
        cout << "}\n";

        saiEscopo();
    }
    |
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
            | TK_TIPO TK_ID '{' { entraEscopo(); } CMDS '}'
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
            | TK_WHILE '(' EXP ')'
            {
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
            | TK_DO
              {
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
            | BLOCO TK_WHILE '(' EXP ')' FIM_LINHA
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
            | TK_FOR '(' FOR_INICIA ';' EXP ';' FOR_INCREM ')'
            {
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
                    yyerror("Erro semântico: 'pare' (break) fora de um laço.");
                }
                $$.traducao = "\tgoto " + pilhaRotulosFimLoop.top() + ";\n";
            }
            | TK_CONTINUE FIM_LINHA
            {
                if (pilhaRotulosProxIteracao.empty()) {
                    yyerror("Erro semântico: 'passa' (continue) fora de um laço.");
                }
                $$.traducao = "\tgoto " + pilhaRotulosProxIteracao.top() + ";\n";
            }
            | TK_PRINT '(' EXP ')' FIM_LINHA
            {
                if ($3.tipo == "string_literal") {
                    // Cria uma temporária para o ponteiro da string
                    string temp_print_str = insereTemporariasTabelaSimbolos("", "string");
                    
                    // Cria uma temporária para o tamanho (int)
                    string temp_size_var = insereTemporariasTabelaSimbolos("", "int");
                    
                    int tamanho = tamanho_string($3.label);

                    stringstream ss;
                    // 1. Atribui o tamanho à variável temporária de tamanho
                    ss << "\t" << temp_size_var << " = " << tamanho << ";\n";
                    
                    // 2. Usa a variável de tamanho no malloc
                    ss << "\t" << temp_print_str << " = (char*) malloc(" << temp_size_var << ");\n";
                    
                    ss << "\tstrcpy(" << temp_print_str << ", " << $3.label << ");\n";
                    ss << "\tprintf(\"%s\\n\", " << temp_print_str << ");\n";
                    ss << "\tfree(" << temp_print_str << ");\n";

                    $$.traducao = ss.str();

                } else {
                    // Lógica para printar variáveis (permanece a mesma)
                    string formato = "";
                    string tipoVar = pegaTipo($3.tipo);
                    
                    if (tipoVar == "int") formato = "%d";
                    else if (tipoVar == "float") formato = "%f";
                    else if (tipoVar == "char") formato = "%c";
                    else if (tipoVar == "bool") formato = "%d";
                    else if (tipoVar == "string") formato = "%s";
                    else {
                        yyerror("Tipo inválido para 'fala' (print): " + $3.tipo);
                    }
                    
                    $$.traducao = $3.traducao + "\tprintf(\"" + formato + "\\n\", " + $3.label + ");\n";
                }
            }
            | TK_SCAN '(' TK_ID ')' FIM_LINHA
            {
                TIPO_SIMBOLO varSimbolo;
                if (!verificaTabelaSimbolos($3.label)) {
                    yyerror("Variável '" + $3.label + "' não declarada para 'ouve' (scan).");
                } else {
                    varSimbolo = pegaVariavelTabelaSimbolos($3.label);
                }

                if (varSimbolo.tipoVariavel == "string") {
                    stringstream ss;
                    ss << "\tfree(" << varSimbolo.label << ");\n";
                    ss << "\t" << varSimbolo.label << " = (char*) malloc(" << SCAN_BUFFER_SIZE << ");\n";
                    
                    // Alterado para usar "%s" diretamente, como solicitado.
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
            ;


FOR_INICIA  : DECL { $$.traducao = $1.traducao; }
            | ATR { $$.traducao = $1.traducao; }
            | { $$.traducao = ""; }
            ;
FOR_INCREM  : ATR
            { $$.traducao = $1.traducao; }
            | EXP
            { $$.traducao = $1.traducao; }
            |
            { $$.traducao = ""; }
            ;


DECL        : TK_TIPO TK_ID 
            {
               if($1.label == "falada") {
                   insereFixasTabelaSimbolos($2.label, "string");
               } else {
                   insereFixasTabelaSimbolos($2.label, $1.label);
               }
               $$.traducao = "";
            }
            | TK_TIPO TK_ID '=' EXP
            {
                insereFixasTabelaSimbolos($2.label, $1.label);
                TIPO_SIMBOLO varSimbolo = pegaVariavelTabelaSimbolos($2.label);

                string tipoExp = pegaTipo($4.tipo);
                if (varSimbolo.tipoVariavel != tipoExp && tipoExp != "string" && $4.tipo != "string_literal") {
                    yyerror("Tipo incompatível na declaração de '" + $2.label + "'.");
                }

                if (varSimbolo.tipoVariavel == "string") {
                    string temp_tamanho = insereTemporariasTabelaSimbolos("", "int");
                    stringstream ss;

                    if ($4.tipo == "string_literal") {
                        int tamanho = tamanho_string($4.label);
                        ss << "\t" << temp_tamanho << " = " << tamanho << ";\n";
                        ss << "\t" << varSimbolo.label << " = (char*) malloc(" << temp_tamanho << ");\n";
                        ss << "\tstrcpy(" << varSimbolo.label << ", " << $4.label << ");\n";
                    } else {
                        ss << $4.traducao;
                        ss << "\t" << temp_tamanho << " = strlen(" << $4.label << ") + 1;\n";
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

        if (tipo == "string" || $1.label == "falada") {
            insereFixasTabelaSimbolos($2.label, "string", true, tamanho1, tamanho2);
        } else {
            insereFixasTabelaSimbolos($2.label, $1.label, true, tamanho1, tamanho2);
        }
        $$.traducao = "";
    }
    | TK_TIPO TK_ID '[' TK_INT ']'
    {
        string tipo = pegaTipo($1.label);
        int tamanho = stoi($4.label);

        if (tipo == "string" || $1.label == "falada") {
            insereFixasTabelaSimbolos($2.label, "string", true, tamanho);
        } else {
            insereFixasTabelaSimbolos($2.label, $1.label, true, tamanho);
        }
        $$.traducao = "";
    }
            ;

ATR         : TK_ID '=' EXP
            {
                TIPO_SIMBOLO varEsquerda = pegaVariavelTabelaSimbolos($1.label);
                
                string tipoExp = pegaTipo($3.tipo);
                if (varEsquerda.tipoVariavel != tipoExp && tipoExp != "string" && $3.tipo != "string_literal") {
                    yyerror("Tipo incompatível na atribuição para '" + $1.label + "'.");
                }

                $$.label = varEsquerda.label;

                if (varEsquerda.tipoVariavel == "string") {
                    string temp_tamanho = insereTemporariasTabelaSimbolos("", "int");
                    stringstream ss;

                    ss << "\tfree(" << varEsquerda.label << ");\n";

                    if ($3.tipo == "string_literal") {
                        int tamanho = tamanho_string($3.label);
                        ss << "\t" << temp_tamanho << " = " << tamanho << ";\n";
                        ss << "\t" << varEsquerda.label << " = (char*) malloc(" << temp_tamanho << ");\n";
                        ss << "\tstrcpy(" << varEsquerda.label << ", " << $3.label << ");\n";
                    } else {
                        ss << $3.traducao;
                        ss << "\t" << temp_tamanho << " = strlen(" << $3.label << ") + 1;\n";
                        ss << "\t" << varEsquerda.label << " = (char*) malloc(" << temp_tamanho << ");\n";
                        ss << "\tstrcpy(" << varEsquerda.label << ", " << $3.label << ");\n";
                    }
                    $$.traducao = ss.str();
                    variaveisAlocadas.insert(varEsquerda.label); 
                } else {
                    $$.traducao = $3.traducao + "\t" + varEsquerda.label + " = " + $3.label + ";\n";
                }
            }
            |
            TK_ID '[' EXP ']' '=' EXP
    {
        if (!verificaTabelaSimbolos($1.label))
            yyerror("Variável '" + $1.label + "' não declarada para atribuição em índice.");

        TIPO_SIMBOLO temp = pegaVariavelTabelaSimbolos($1.label);

        if (!temp.isArray)
            yyerror("Variável '" + $1.label + "' não é um vetor.");

        if ($3.tipo != "int")
            yyerror("Índice de vetor deve ser inteiro: tipo recebido '" + $3.tipo + "'.");

        if (temp.tipoVariavel != pegaTipo($6.tipo))
            yyerror("Tipo incompatível ao atribuir em vetor '" + $1.label + "'.");

        $$.label = temp.label;
        $$.traducao = $3.traducao
                     + $6.traducao
                     + "\t" + temp.label 
                     + "[" + $3.label + "] = " + $6.label + ";\n";
    }
    |TK_ID '[' EXP ']' '[' EXP ']' '=' EXP
    {
    if (!verificaTabelaSimbolos($1.label))
        yyerror("Matriz não declarada: " + $1.label);

    TIPO_SIMBOLO mat = pegaVariavelTabelaSimbolos($1.label);

    if (!mat.isArray || mat.arraySize2 == 0)
        yyerror("'" + $1.label + "' não é matriz 2D.");

    if ($3.tipo != "int" || $6.tipo != "int")
        yyerror("Índices de matriz devem ser inteiros.");

    if (mat.tipoVariavel != pegaTipo($9.tipo))
        yyerror("Tipo incompatível ao atribuir em matriz '" + $1.label + "'.");

    string tempMult = insereTemporariasTabelaSimbolos("temp", "int");
    string tempIdx  = insereTemporariasTabelaSimbolos("temp", "int");

    $$.traducao  = $3.traducao
                 + $6.traducao
                 + "\t" + tempMult + " = " + $3.label + " * " + to_string(mat.arraySize2) + ";\n"
                 + "\t" + tempIdx  + " = " + tempMult + " + " + $6.label + ";\n"
                 + $9.traducao
                 + "\t" + mat.label + "[" + tempIdx + "] = " + $9.label + ";\n";
    }
    | TK_ID '=' TK_ID '[' EXP ']' '[' EXP ']'
        {
        if (!verificaTabelaSimbolos($3.label))
            yyerror("Matriz não declarada: " + $3.label);

        TIPO_SIMBOLO mat = pegaVariavelTabelaSimbolos($3.label);

        if (!mat.isArray || mat.arraySize2 == 0)
            yyerror("'" + $3.label + "' não é matriz 2D.");

        if (!verificaTabelaSimbolos($1.label))
            yyerror("Variável '" + $1.label + "' não declarada.");

        TIPO_SIMBOLO destino = pegaVariavelTabelaSimbolos($1.label);

        if (destino.tipoVariavel != mat.tipoVariavel)
            yyerror("Tipos incompatíveis entre '" + $1.label + "' e matriz '" + $3.label + "'.");

        if ($5.tipo != "int" || $8.tipo != "int")
            yyerror("Índices da matriz devem ser inteiros.");

        string tempMult = insereTemporariasTabelaSimbolos("temp", "int");
        string tempIdx  = insereTemporariasTabelaSimbolos("temp", "int");

        $$.traducao  = $5.traducao
                     + $8.traducao
                     + "\t" + tempMult + " = " + $5.label + " * " + to_string(mat.arraySize2) + ";\n"
                     + "\t" + tempIdx  + " = " + tempMult + " + " + $8.label + ";\n"
                     + "\t" + destino.label + " = " + mat.label + "[" + tempIdx + "];\n";

        $$.label = $1.label;
        $$.tipo  = destino.tipoVariavel;
        }
        | TK_ID '=' TK_ID '[' EXP ']'
{
    if (!verificaTabelaSimbolos($3.label))
        yyerror("Vetor não declarado: " + $3.label);

    TIPO_SIMBOLO vet = pegaVariavelTabelaSimbolos($3.label);

    if (!vet.isArray || vet.arraySize2 != 0)
        yyerror("'" + $3.label + "' não é vetor 1D.");

    if (!verificaTabelaSimbolos($1.label))
        yyerror("Variável '" + $1.label + "' não declarada.");

    TIPO_SIMBOLO destino = pegaVariavelTabelaSimbolos($1.label);

    if (destino.tipoVariavel != vet.tipoVariavel)
        yyerror("Tipos incompatíveis entre '" + $1.label + "' e vetor '" + $3.label + "'.");

    if ($5.tipo != "int")
        yyerror("Índice do vetor deve ser inteiro.");

    $$.traducao  = $5.traducao
                 + "\t" + $1.label + " = " + vet.label + "[" + $5.label + "];\n";

    $$.label = destino.label;
    $$.tipo  = destino.tipoVariavel;
}
      ;  

EXP         : EXP '+' TERMO 
            {   
                
                if(debug) cout << "[DEBUG] Operação + entre: " << $1.tipo << " e " << $3.tipo 
                << "\n  Label1: " << $1.label << " | Label2: " << $3.label << endl;

                $$.tipo = infereTipo($1.tipo, $3.tipo);
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao;

                if($1.tipo == "int" && $3.tipo == "float") 
                {
                    if(debug) cout << "[DEBUG] Convertendo int para float: " << $1.label << endl;
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    $$.traducao += "\t" + temporario + " = (float) " + $1.label + ";\n" +
                    "\t" + $$.label + " = " + temporario + " + " + $3.label + ";\n"; 

                }
                else if($1.tipo == "float" && $3.tipo == "int") 
                {
                    if(debug) cout << "[DEBUG] Convertendo int para float: " << $1.label << endl;
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    $$.traducao += "\t" + temporario + " = (float) " + $3.label + ";\n" + 
                    "\t" + $$.label + " = " + $1.label + " + " + temporario + ";\n"; 
                }
                else if($1.tipo == "bool" || $3.tipo == "bool" || $1.tipo == "string" || $3.tipo == "string")
                {
                    string erro = "[ERRO] Operação '+' inválida entre tipos " + $1.tipo + " e " + $3.tipo;
                    yyerror(erro);
                }
                else 
                {
                    $$.traducao += "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
                }
            }
            | EXP '-' TERMO 
            {   
                if(debug) cout << "\n[DEBUG] Operação - entre: " << $1.tipo << " e " << $3.tipo 
                << "\n\t  Label1: " << $1.label << " | Label2: " << $3.label << endl;
                $$.tipo = infereTipo($1.tipo, $3.tipo);
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao;
                
                if($1.tipo == "int" && $3.tipo == "float") 
                {
                    if(debug) cout << "[DEBUG] Convertendo int para float: " << $1.label << endl;
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    $$.traducao += "\t" + temporario + " = (float) " + $1.label + ";\n" +
                    "\t" + $$.label + " = " + temporario + " - " + $3.label + ";\n"; 

                }
                else if($1.tipo == "float" && $3.tipo == "int") 
                {
                    if(debug) cout << "[DEBUG] Convertendo int para float: " << $1.label << endl;
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    $$.traducao += "\t" + temporario + " = (float) " + $3.label + ";\n" + 
                    "\t" + $$.label + " = " + $1.label + " - " + temporario + ";\n"; 
                }
                else if($1.tipo == "bool" || $3.tipo == "bool"|| $1.tipo == "string" || $3.tipo == "string")
                {
                    string erro = "[ERRO] Operação '-' inválida entre tipos " + $1.tipo + " e " + $3.tipo;
                    yyerror(erro);
                }
                else 
                {
                    $$.traducao += "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
                }
            }
            | EXP '>' TERMO 
            {   
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);

                if(($1.tipo == "int" && $3.tipo == "float") || ($1.tipo == "float" && $3.tipo == "int")) 
                { 
                    string erro = "[ERRO] Operação '>' inválida entre tipos " + $1.tipo + " e " + $3.tipo;
                    yyerror(erro);
                }
                else if($1.tipo == "bool" || $3.tipo == "bool" || $1.tipo == "string" || $3.tipo == "string" )
                    yyerror("Operandos inválidos\n");
                    
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " > " + $3.label + ";\n";
            }
            | EXP '<' TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);

                if(($1.tipo == "int" && $3.tipo == "float") || ($1.tipo == "float" && $3.tipo == "int")) 
                {
                    string erro = "[ERRO] Operação '<' inválida entre tipos " + $1.tipo + " e " + $3.tipo;
                    yyerror(erro);
                }
                else if($1.tipo == "bool" || $3.tipo == "bool" || $1.tipo == "string" || $3.tipo == "string")
                    yyerror("Operandos inválidos\n");
                
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " < " + $3.label + ";\n";
            }
            | EXP TK_MAIOR_IGUAL TERMO
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                if(($1.tipo == "int" && $3.tipo == "float") || ($1.tipo == "float" && $3.tipo == "int")) 
                {
                    string erro = "[ERRO] Operação '>=' inválida entre tipos " + $1.tipo + " e " + $3.tipo;
                    yyerror(erro);
                }
                else if($1.tipo == "bool" || $3.tipo == "bool" || $1.tipo == "string" || $3.tipo == "string")
                    yyerror("Operandos inválidos\n");
                
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " >= " + $3.label + ";\n";
            }
            | EXP TK_MENOR_IGUAL TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);

                if(($1.tipo == "int" && $3.tipo == "float") || ($1.tipo == "float" && $3.tipo == "int")) 
                {
                    string erro = "[ERRO] Operação '<=' inválida entre tipos " + $1.tipo + " e " + $3.tipo;
                    yyerror(erro);
                }
                else if($1.tipo == "bool" || $3.tipo == "bool" || $1.tipo == "string" || $3.tipo == "string")
                    yyerror("Operandos inválidos\n");
                
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " <= " + $3.label + ";\n";
            }
            | EXP TK_DIFERENTE TERMO
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                if(($1.tipo == "int" && $3.tipo == "float") || ($1.tipo == "float" && $3.tipo == "int")) 
                {
                    string erro = "[ERRO] Operação '!=' inválida entre tipos " + $1.tipo + " e " + $3.tipo;
                    yyerror(erro);
                }
                else if($1.tipo == "bool" || $3.tipo == "bool" || $1.tipo == "string" || $3.tipo == "string")
                    yyerror("Operandos inválidos\n");
                
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " != " + $3.label + ";\n";          
            }
            | EXP TK_IGUAL TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                if(($1.tipo == "int" && $3.tipo == "float") || ($1.tipo == "float" && $3.tipo == "int")) 
                    {
                        string erro = "[ERRO] Operação '==' inválida entre tipos " + $1.tipo + " e " + $3.tipo;
                        yyerror(erro);
                    }
                else if($1.tipo == "bool" || $3.tipo == "bool" || $1.tipo == "string" || $3.tipo == "string")
                    yyerror("Operandos inválidos\n");
                
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " == " + $3.label + ";\n";          
            }
            | EXP TK_E_LOGICO TERMO
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);

                if($1.tipo != "bool" || $3.tipo != "bool")
                    yyerror("Operandos inválidos\n");

                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " && " + $3.label + ";\n";  
            }
            | EXP TK_OU_LOGICO TERMO
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);

                if($1.tipo != "bool" || $3.tipo != "bool")
                    yyerror("Operandos inválidos\n");

                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " || " + $3.label + ";\n";  
            }
            | TERMO             
            { 
                $$.label = $1.label;
                $$.traducao = $1.traducao;
                $$.tipo = $1.tipo;      
            } 
            ;

TERMO       : TERMO '*' FATOR
            {   
                $$.tipo = infereTipo($1.tipo, $3.tipo);
                $$.label = insereTemporariasTabelaSimbolos("",   $$.tipo);
                $$.traducao = $1.traducao + $3.traducao;

                if($1.tipo == "int" && $3.tipo == "float") 
                {
                    if(debug) cout << "[DEBUG] Convertendo int para float: " << $1.label << endl;
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    $$.traducao += "\t" + temporario + " = (float) " + $1.label + ";\n" +
                    "\t" + $$.label + " = " + temporario + " * " + $3.label + ";\n"; 

                }
                else if($1.tipo == "float" && $3.tipo == "int") 
                {
                    if(debug) cout << "[DEBUG] Convertendo int para float: " << $1.label << endl;
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    $$.traducao += "\t" + temporario + " = (float) " + $3.label + ";\n" + 
                    "\t" + $$.label + " = " + $1.label + " * " + temporario + ";\n"; 
                }
                else if($1.tipo == "bool" || $3.tipo == "bool" || $1.tipo == "string" || $3.tipo == "string")
                {
                    string erro = "[ERRO] Operação '*' inválida entre tipos " + $1.tipo + " e " + $3.tipo;
                    yyerror(erro);
                }
                else 
                {
                    $$.traducao = "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
                }
            }
            | TERMO '/' FATOR 
            { 
                $$.tipo = infereTipo($1.tipo, $3.tipo);
                $$.label = insereTemporariasTabelaSimbolos("",   $$.tipo);
                $$.traducao = $1.traducao + $3.traducao;

                if($1.tipo == "int" && $3.tipo == "float") 
                {
                    if(debug) cout << "[DEBUG] Convertendo int para float: " << $1.label << endl;
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    $$.traducao += "\t" + temporario + " = (float) " + $1.label + ";\n" +
                    "\t" + $$.label + " = " + temporario + " / " + $3.label + ";\n"; 

                }
                else if($1.tipo == "float" && $3.tipo == "int") 
                {
                    if(debug) cout << "[DEBUG] Convertendo int para float: " << $1.label << endl;
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    $$.traducao += "\t" + temporario + " = (float) " + $3.label + ";\n" + 
                    "\t" + $$.label + " = " + $1.label + " / " + temporario + ";\n"; 
                }
                else if($1.tipo == "bool" || $3.tipo == "bool" || $1.tipo == "string" || $3.tipo == "string")
                {
                    string erro = "[ERRO] Operação '/' inválida entre tipos " + $1.tipo + " e " + $3.tipo;
                    yyerror(erro);
                }
                else 
                {
                    $$.traducao = "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
                }
            }
            | FATOR             
            { 
                $$.label = $1.label;
                $$.traducao = $1.traducao; 
                $$.tipo = $1.tipo;
            }
            ;

FATOR       : '(' EXP ')' 
            { 
                $$.label = $2.label;
                $$.traducao = $2.traducao;
                $$.tipo = $2.tipo;
            }
            | '(' TK_TIPO ')' FATOR
            {   
                $$.label = insereTemporariasTabelaSimbolos("", $2.label);
                $$.tipo = $2.label;

                $$.traducao = $4.traducao +
                "\t" + $$.label + " = (" + $2.label + ") " + $4.label + ";\n";
            }
            | TK_ID
            {
                TIPO_SIMBOLO temp;

                if(!verificaTabelaSimbolos($1.label))
                    yyerror("Não foi inicializado uma das variáveis");
                else 
                    temp = pegaVariavelTabelaSimbolos($1.label);
                
                if(debug) cout << "[DEBUG] Acessando variável: " << $1.label 
                << " (Tipo: " << temp.tipoVariavel << ")\n";
                    if (temp.isArray)  
                    yyerror("Acesso inválido: vetor/matriz '" + $1.label + "' usado sem índice.");
                $$.label = temp.label;
                $$.tipo = temp.tipoVariavel;
                $$.traducao = "";
            }
            | TK_NEGACAO TK_ID
            {
                 $$.tipo = "bool";

                TIPO_SIMBOLO temp;

                if(!verificaTabelaSimbolos($2.label))
                    yyerror("Não foi inicializado uma das variáveis");
                else 
                    temp = pegaVariavelTabelaSimbolos($2.label);

                if("bool" != temp.tipoVariavel)
                    yyerror("Operação inválida para o tipo da variável");

                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                $$.traducao = "\t" + $$.label + " = !" + temp.label + ";\n";
            }
            | TK_INT
            { 
                $$.label = insereTemporariasTabelaSimbolos("", "nmr");
                $$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
                $$.tipo = "int"; 
            }
            | TK_FLOAT
            {   
                $$.label = insereTemporariasTabelaSimbolos("", "ncv");
                $$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n"; 
                $$.tipo = "float"; 
            }
            | TK_BOOLEAN
            {
                $$.label = insereTemporariasTabelaSimbolos("", "pp");
                string valor = pegaBooleano($1.label);

                if(valor == "error") yyerror("Valor atribuído de forma errada!");

                $$.traducao = "\t" + $$.label + " = " + valor + ";\n";
                $$.tipo = "bool"; 
            }
            | TK_CHAR
            {
                $$.label = insereTemporariasTabelaSimbolos("", "letra");
                $$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
                $$.tipo = "char"; 
            }
            | TK_STRING
            {
                $$.label = $1.traducao;
                $$.tipo = "string_literal";
                $$.traducao = "";
            }
            | TK_ID '[' EXP ']' {
            if (!verificaTabelaSimbolos($1.label))
                yyerror("Vetor '" + $1.label + "' não declarado.");

            TIPO_SIMBOLO vet = pegaVariavelTabelaSimbolos($1.label);

            if (!vet.isArray || vet.arraySize2 != 0)
                yyerror("'" + $1.label + "' não é vetor 1D.");

            if ($3.tipo != "int")
                yyerror("Índice do vetor deve ser inteiro.");

            string temp = insereTemporariasTabelaSimbolos("", vet.tipoVariavel);

            $$.traducao = $3.traducao +
                       "\t" + temp + " = " + vet.label + "[" + $3.label + "];\n";

            $$.label = temp;
            $$.tipo = vet.tipoVariavel;
            }
            | TK_ID '[' EXP ']' '[' EXP ']' {
            if (!verificaTabelaSimbolos($1.label))
                yyerror("Matriz '" + $1.label + "' não declarada.");

            TIPO_SIMBOLO mat = pegaVariavelTabelaSimbolos($1.label);

            if (!mat.isArray || mat.arraySize2 == 0)
                yyerror("'" + $1.label + "' não é matriz 2D.");

            if ($3.tipo != "int" || $6.tipo != "int")
                yyerror("Índices da matriz devem ser inteiros.");

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

%%

#include "lex.yy.c"

int yyparse();

int tamanho_string(string texto){ 
    int tamanhoString = 0;
    int i = 0;
    while(texto[i] != '\0'){
        tamanhoString++; 
        i++;
    }
    return tamanhoString-1;
}
string novo_rotulo() {
    return "L" + to_string(contador_rotulos++);
}

string geraNomeTemp(string tipo)
{
    
    qntdVariaveisTemp++;

    if(tipo == "nmr" || tipo == "int")
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "int"});
    else if(tipo == "ncv" || tipo == "float")
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "float"});
    else if(tipo == "pp" || tipo == "bool")
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "int"});
    else if(tipo == "letra" || tipo == "char")
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "char"});
    else if(tipo == "falada" || tipo == "string")
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "char_array"});
    else
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "null"});
      
    return "T" + to_string(qntdVariaveisTemp); 
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

    if(debug) cout << "[DEBUG] Inserindo TEMPORARIA na tabela (escopo atual): " << temp.nomeVariavel << " (Tipo: " << temp.tipoVariavel << ")\n";

    return temp.label;
}

void insereFixasTabelaSimbolos(string nome, string tipo,bool ehArray, int tamanhoArray, int tamanhoArray2)
{   
    if (pilhaTabelasSimbolos.empty())
    {
        yyerror("Erro de lógica: Tentou declarar variável sem um escopo ativo.");
        return;
    }

    map<string, TIPO_SIMBOLO>& escopoAtual = pilhaTabelasSimbolos.back();

    if (escopoAtual.count(nome))
    {
        yyerror("Erro: Variável '" + nome + "' já declarada neste escopo.");
        return;
    }

    if (debug) cout << "[DEBUG] Inserindo FIXA na tabela (escopo atual): " << nome << " (Tipo: " << tipo << ")\n";

    TIPO_SIMBOLO temp;
    temp.nomeVariavel = nome;
    temp.tipoVariavel = pegaTipo(tipo);
    if(debug) cout << "[DEBUG] Tipo processado em pegaTipo: '" << temp.tipoVariavel << "' para o tipo recebido: '" << tipo << "'\n";
    temp.label = geraNomeTemp(tipo);

    temp.isArray = ehArray;
    temp.arraySize = tamanhoArray;
    temp.arraySize2 = tamanhoArray2;

    escopoAtual[nome] = temp;
}

bool verificaTabelaSimbolos(string nome)
{

    for (int i = pilhaTabelasSimbolos.size() - 1; i >= 0; --i)
    {
        if (pilhaTabelasSimbolos[i].count(nome)) 
        { 
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
    return {};
}

void printTabelaSimbolos()
{
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
    if(tipo == "nmr" || tipo == "int")
        return "int";
    else if(tipo == "ncv" || tipo == "float")
        return "float";
    else if(tipo == "letra" || tipo == "char")
        return "char";
    else if(tipo == "pp" || tipo == "bool")
        return "bool";
     else if(tipo == "falada" || tipo == "string")
        return "string";    
    else 
        return "null";      
}

string infereTipo(string tipo1, string tipo2)
{   
    if(debug) cout << "[DEBUG] Inferindo tipo entre: " << tipo1 << " e " << tipo2 << endl;
    if(tipo1 == "int" && tipo1 == tipo2) return "int";
    else if(tipo1 == "char" || tipo2 == "char") yyerror("Operando inválido!");

    return "float";
}

string pegaBooleano(string valor)
{
    if(valor == "reto") return "true";
    else if(valor == "torto") return "false";
    else return "error";
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
    cout << "Na linha " << yylinha << ": "<< MSG << endl;
    exit (0);
}