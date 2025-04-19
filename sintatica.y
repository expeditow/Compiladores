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

struct infos
{
    string nomeVariavel; // célula de memória que vamos armazenar, inicializando la no c
    string tipoVar;  // tipo da célula, muda a representação dependendo do tipo

    // oq mais precisamos aq p guardar na tabela de símbolos?
};

int yylex(void);
void yyerror(string);

set<string> temporarias;

string  geraNomeTemp();
%}

%token TK_NUM TK_ID
%token FIM_LINHA
%start START


%%

START 	    :  CMDS
            {   
                string declaracoes = "";
                for(auto i: temporarias){
                    declaracoes += "\tint " + i + ";\n";
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
            | EXP           { $$.traducao = $1.traducao; }
            ;

EXP         : EXP '+' TERMO 
            { 
                $$.label = geraNomeTemp();
                $$.traducao = $1.traducao + $3.traducao + "\t" + 
                $$.label + " = " + $1.label + " + " + $3.label + ";\n";
            }
            | EXP '-' TERMO 
            { 
                $$.label = geraNomeTemp();
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
                $$.label = geraNomeTemp();
                $$.traducao = "\t" + $$.label + ";\n" + "\t" + $$.label + " = " + $1.traducao + ";\n";
            }
            ;

TERMO       : TERMO '*' FATOR 
            { 
                $$.label = geraNomeTemp();
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
            }
            | TERMO '/' FATOR 
            { 
                $$.label =geraNomeTemp();
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
            | TK_NUM         // só aqui que a gente gera declaração
            { 
                $$.label = geraNomeTemp();
                $$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n"; 
            }
            ;

%%

#include "lex.yy.c"

int yyparse();

string geraNomeTemp(){
    
    qntdVariaveisTemp++;
    temporarias.insert("T" + to_string(qntdVariaveisTemp));
    return "T" + to_string(qntdVariaveisTemp);
}

int main( int argc, char* argv[] )
{   
    set<string> temporarias;
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
