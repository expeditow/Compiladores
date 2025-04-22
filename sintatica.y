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
    string tipoVar;  // int, float, double
    string label; // tipo registrador

} infos;

int yylex(void);
void yyerror(string);

set<pair<string,string>> temporarias;

vector<infos> tabelaSimbolos;

string  geraNomeTemp(string tipo);


%}

%token TK_INT TK_ID TK_FLOAT
%token TK_TIPO TK_DOISP
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

CMD         : EXP FIM_LINHA { $$.traducao = $1.traducao; }
            | FIM_LINHA     { $$.traducao = "";          }
            | ATR           { $$.traducao = $1.traducao; }
            | EXP           { $$.traducao = $1.traducao; }
            ;


ATR         : TK_ID '=' EXP
            {
                $$.label = $1.label; 
                $$.traducao = $3.traducao + "\t" + $1.label + " = " + $3.label + ";\n";
            }
            ;
        

EXP         : EXP '+' TERMO 
            { 
                $$.label = geraNomeTemp("int");
                $$.traducao = $1.traducao + $3.traducao + "\t" + 
                $$.label + " = " + $1.label + " + " + $3.label + ";\n";
            }
            | EXP '-' TERMO 
            { 
                $$.label = geraNomeTemp("int");
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
                $$.label = geraNomeTemp("int");
                $$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
            }
            ;

TERMO       : TERMO '*' FATOR 
            { 
                $$.label = geraNomeTemp("int");
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
            }
            | TERMO '/' FATOR 
            { 
                $$.label = geraNomeTemp("int");
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
                $$.label = geraNomeTemp("int");
                $$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n"; 
            }
            | TK_FLOAT
            {
                $$.label = geraNomeTemp("float");
                $$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n"; 
            }

            ;

%%

#include "lex.yy.c"

int yyparse();

string geraNomeTemp(string tipo)
{
    
    qntdVariaveisTemp++;

    if(tipo == "int")
    {
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "int"});
    }
    else if(tipo == "float")
    {
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "float"});
    }

    return "T" + to_string(qntdVariaveisTemp);
}

void insereTabelaSimbolos(string nome, string tipo, string label)
{
    infos temp = {nome, tipo, label};
    tabelaSimbolos.push_back(temp);
}

int main( int argc, char* argv[] )
{   
    set<pair<string,string>> temporarias;
    int qntdVariaveisTemp = 0;
    int linhas = 0;

	yyparse();

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}				
