%{
#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

#define YYSTYPE atributos

using namespace std;

int qntdVariaveisTemp = 0;
int linhas;

struct atributos // Atributos aqui é cada nó da árvore, cada nó possui:
{
	string label;       // A variável temporária atribuída
	string traducao;    // A tradução em código intermediário
    string tipo;        // O tipo, p casos de operações que precisamos criar uma nova label
};

typedef struct
{
    string nomeVariavel; // nome no código fonte
    string tipoVariavel;  // int, float, double
    string label; // tipo registrador

} TIPO_SIMBOLO;

int yylex(void);
void yyerror(string);

set<pair<string,string>> temporarias;

vector<TIPO_SIMBOLO> tabelaSimbolos;

bool verificaTabelaSimbolos(string nome);
TIPO_SIMBOLO pegaVariavelTabelaSimbolos(string nome);
void printTabelaSimbolos();

void insereFixasTabelaSimbolos(string nome, string tipo);
string insereTemporariasTabelaSimbolos(string nome, string tipo);

string geraNomeTemporarias(string tipo);
string pegaTipo(string tipo);
string infereTipo(string tipo1, string tipo2);
string pegaBooleano(string valor);

bool debug = false;
#define true 1
#define false 0

extern int yylinha;

%}

%token TK_TIPO TK_ID
%token TK_INT TK_FLOAT TK_BOOLEAN TK_CHAR
%token TK_MAIOR_IGUAL TK_MENOR_IGUAL TK_DIFERENTE TK_IGUAL TK_E_LOGICO TK_OU_LOGICO TK_NEGACAO
%token FIM_LINHA

%start START


%%

START 	    :  CMDS
            {   
                if(debug) cout << "[DEBUG] Árvore completa gerada. Tradução:\n";

                string defines = "\n\t#define true 1\n\t#define false 0\n\n\n";
                string declaracoes = "";
                for(auto i: temporarias){
                    declaracoes += "\t" + i.second + " " + i.first + ";\n";
                }
                cout << defines << declaracoes << endl << $1.traducao << endl;
            }
            |
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
            | EXP            { $$.traducao = $1.traducao; }
            | FIM_LINHA      { $$.traducao = "";          }
            ;


DECL        : TK_TIPO TK_ID { insereFixasTabelaSimbolos($2.label, $1.label); }
            ;

ATR         : TK_ID '=' EXP
            {

                TIPO_SIMBOLO temp;

                if(!verificaTabelaSimbolos($1.label))
                    yyerror("Não foi declarado essa variável");
                else
                    temp = pegaVariavelTabelaSimbolos(($1.label));

                if(debug) cout << "[DEBUG] Atribuição: " << $1.label << " = " << $3.label 
                << "\n  Tipos: " << temp.tipoVariavel << " <- " << $3.tipo << endl;

                if(temp.tipoVariavel != pegaTipo($3.tipo))
                    yyerror("Variavel nao suporta valor atribuido");

                $$.label = temp.label;
                $$.traducao = $3.traducao + "\t" + temp.label + " = " + $3.label + ";\n";

            }
        

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
                else 
                {
                    $$.traducao = "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
                }
            }
            | EXP '>' TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " > " + $3.label + ";\n";
            }
            | EXP '<' TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " < " + $3.label + ";\n";
            }
            | EXP TK_MAIOR_IGUAL TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " >= " + $3.label + ";\n";
            }
            | EXP TK_MENOR_IGUAL TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + "<= " + $3.label + ";\n";
            }
            | EXP TK_DIFERENTE TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " != " + $3.label + ";\n";           
            }
            | EXP TK_IGUAL TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTemporariasTabelaSimbolos("", $$.tipo);
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
                $$.label = insereTemporariasTabelaSimbolos("",  $$.tipo);
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
            }
            | TERMO '/' FATOR 
            { 
                $$.tipo = infereTipo($1.tipo, $3.tipo);
                $$.label = insereTemporariasTabelaSimbolos("",  $$.tipo);
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
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

                $$.label = temp.label;
                $$.tipo = temp.tipoVariavel;
                $$.traducao = "";
            }
            | TK_NEGACAO TK_ID
            {
                 $$.tipo = "bool";

                TIPO_SIMBOLO temp;

                // verificao se é a variável correta

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
            ;

%%

#include "lex.yy.c"

int yyparse();

// Função para geração de variáveis temporárias
string geraNomeTemp(string tipo)  // Dá para melhorar essa função
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
    else // caso em que n tenha nenhum tipo atribuído - vamos inicializar "vazio" - ou em dinâmico
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "null"});
     
    return "T" + to_string(qntdVariaveisTemp); 
}

// Vai retonar ao registrador assoaciado a variável
string insereTemporariasTabelaSimbolos(string nome, string tipo)
{   
    if(debug) cout << "[DEBUG] Inserindo TEMPORARIA na tabela: " << nome << " (Tipo: " << tipo << ")\n";
    TIPO_SIMBOLO temp;

    temp.nomeVariavel = geraNomeTemp(tipo);
    temp.tipoVariavel = pegaTipo(tipo); // Necessariamente precisa ser isso, pois, ele trata dos nomes que escolhemos na nossa linguagem
    temp.label = temp.nomeVariavel;
    
    tabelaSimbolos.push_back(temp);

    return temp.label;
}

void insereFixasTabelaSimbolos(string nome, string tipo)
{   
    if(debug) cout << "[DEBUG] Inserindo FIXA na tabela: " << nome << " (Tipo: " << tipo << ")\n";
    TIPO_SIMBOLO temp;

    temp.nomeVariavel = nome;
    temp.tipoVariavel = pegaTipo(tipo);
    temp.label = geraNomeTemp(tipo);
    
    tabelaSimbolos.push_back(temp);
}

// Função para verificar se existe na tabela de símbolos
bool verificaTabelaSimbolos(string nome)
{
    bool encontrei = false;

    for(int i = 0; i < tabelaSimbolos.size(); i++)
        if(tabelaSimbolos[i].nomeVariavel == nome)
            encontrei = true;
    
    return encontrei;
}

// Só para pegar a variável na tabela de símbolos, tenho que setar em um caso onde não tenha
TIPO_SIMBOLO pegaVariavelTabelaSimbolos(string nome)
{

    TIPO_SIMBOLO temp;
    for(int i = 0; i < tabelaSimbolos.size(); i++)
    {
        if(tabelaSimbolos[i].nomeVariavel == nome)
        {
            temp = tabelaSimbolos[i];
        }
    }

    return temp;
}

// Função para printar 
void printTabelaSimbolos()
{
    for(int i = 0; i < tabelaSimbolos.size(); i++)
    {
        cout << "Simbolo [" <<  i+1 << "] : nome: " <<  tabelaSimbolos[i].nomeVariavel << " tipo: " 
        << tabelaSimbolos[i].tipoVariavel << " label: " << tabelaSimbolos[i].label << endl;

    }
    cout << endl;
}

// Função para converter tipo
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
    else 
        return "null";    
}

string infereTipo(string tipo1, string tipo2)
{   
    if(debug) cout << "[DEBUG] Inferindo tipo entre: " << tipo1 << " e " << tipo2 << endl;
    if(tipo1 == "int" && tipo1 == tipo2) return "int";
    else if(tipo1 == "char" || tipo2 == "char") yyerror("Operando inválido!");

    else return "float";
}

string pegaBooleano(string valor)
{
    if(valor == "reto") return "true";
    else if(valor == "torto") return "false";
    else return "error"; // erro
}

int main( int argc, char* argv[] )
{   
    yyparse();
    printTabelaSimbolos(); // - fins depurativos

	return 0;
}

void yyerror( string MSG )
{
	cout << "Na linha " << yylinha << ": "<< MSG << endl;
	exit (0);
}				
