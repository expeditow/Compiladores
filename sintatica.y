%{
#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

#define YYSTYPE atributos

using namespace std;

int qntdVariaveisTemp;
int linhas;

struct atributos
{
	string label;
	string traducao;
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
TIPO_SIMBOLO getVariavelTabelaSimbolos(string nome);
void printTabelaSimbolos();
string insereTabelaSimbolos(string nome, string tipo);
string geraNomeTemp(string tipo);
string getTipo(string tipo);

%}

%token TK_INT TK_ID TK_FLOAT TK_TIPO
%token FIM_LINHA

%start START


%%

START 	    :  CMDS
            {   
                string declaracoes = "";
                for(auto i: temporarias){
                    declaracoes += "\t" + i.second + " " + i.first + ";\n";
                }
                cout << declaracoes << endl << $1.traducao << endl;
            }
            |
            ;

CMDS        : CMD CMDS
            {
                $$.traducao = $1.traducao + $2.traducao;
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


DECL        : TK_TIPO TK_ID 
            {
                string vazia = insereTabelaSimbolos($2.label, $1.label);
                // só pq eu meio q obrigo a função a retornar
                // p casos de variáveis temporárias
            }
            ;

ATR         : TK_ID '=' EXP
            {
                TIPO_SIMBOLO temp;

                if(!verificaTabelaSimbolos($1.label))
                    yyerror("Não foi declarado essa variável");
                else
                    temp = getVariavelTabelaSimbolos(($1.label));

                $$.label = temp.label;
                $$.traducao = $3.traducao + "\t" + temp.nomeVariavel + " = " + $3.label + ";\n";
            }
            ;
        

EXP         : EXP '+' TERMO 
            { 
                $$.label = insereTabelaSimbolos("", "");
                $$.traducao = $1.traducao + $3.traducao + "\t" + 
                $$.label + " = " + $1.label + " + " + $3.label + ";\n";
            }
            | EXP '-' TERMO 
            { 
                $$.label = insereTabelaSimbolos("", "");
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
            }
            | TERMO         
            { 
                $$.label = $1.label;
                $$.traducao = $1.traducao;      
            } 
            | TK_ID
            {
                
                TIPO_SIMBOLO temp;

                if(!verificaTabelaSimbolos($1.label))
                    yyerror("Não foi inicializado uma das variáveis");
                else 
                    temp = getVariavelTabelaSimbolos($1.label);
                
                $$.label = temp.label;
                $$.traducao = "";
            }
            ;

TERMO       : TERMO '*' FATOR 
            { 
                $$.label = insereTabelaSimbolos("", "");
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
            }
            | TERMO '/' FATOR 
            { 
                $$.label = insereTabelaSimbolos("", "");
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
            }
            | FATOR          
            { 
                $$.label = $1.label;
                $$.traducao = $1.traducao; 
            }
            ;

FATOR       : '(' EXP ')' 
            { 
                $$.label = $2.label;
                $$.traducao = $2.traducao;
            }
            | TK_INT
            { 
                $$.label = insereTabelaSimbolos("", "nmr");
                $$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n"; 
            }
            | TK_FLOAT
            {
                $$.label = insereTabelaSimbolos("", "ncv");
                $$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n"; 
            }
            ;

%%

#include "lex.yy.c"

int yyparse();

string geraNomeTemp(string tipo)
{
    
    qntdVariaveisTemp++;

    if(tipo == "nmr")
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "int"});
    else if(tipo == "ncv")
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "float"});
    else // caso em que n tenha nenhum tipo atribuído - vamos inicializar "vazio"
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "null"});
    
    return "T" + to_string(qntdVariaveisTemp);
}

string insereTabelaSimbolos(string nome, string tipo)    // Vai retonar ao registrador assoaciado a variável
{   
    TIPO_SIMBOLO temp;

    if(nome == "") // Caso de temporários
    {
        temp.nomeVariavel = geraNomeTemp(tipo);
        temp.tipoVariavel = getTipo(tipo); // Necessariamente precisa ser isso, pois, ele trata dos nomes que escolhemos na nossa linguagem
        temp.label = temp.nomeVariavel;
    }
    else // Caso de variáveis declaradas
    {
        temp.nomeVariavel = nome;
        temp.tipoVariavel = getTipo(tipo);
        temp.label = geraNomeTemp(tipo);
    }

    tabelaSimbolos.push_back(temp);

    return temp.label;
}

bool verificaTabelaSimbolos(string nome)
{
    bool encontrei = false;
    TIPO_SIMBOLO temp;

    for(int i = 0; i < tabelaSimbolos.size(); i++)
    {
        if(tabelaSimbolos[i].nomeVariavel == nome)
        {
            encontrei = true;
            temp = tabelaSimbolos[i];
        }
    }

    return encontrei;
}
TIPO_SIMBOLO getVariavelTabelaSimbolos(string nome)
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
void printTabelaSimbolos()
{
    for(int i = 0; i < tabelaSimbolos.size(); i++)
    {
        cout << "Simbolo [" <<  i+1 << "] : nome: " <<  tabelaSimbolos[i].nomeVariavel << " tipo: " 
        << tabelaSimbolos[i].tipoVariavel << " label: " << tabelaSimbolos[i].label << endl;

    }
    cout << endl;
}
string getTipo(string tipo)
{
    if(tipo == "nmr")
        return "int";
    else if(tipo == "ncv")
        return "float";
    else 
        return "null";    
}

int main( int argc, char* argv[] )
{   
    int qntdVariaveisTemp = 0;

	yyparse();

    printTabelaSimbolos(); // - fins depurativos

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}				
