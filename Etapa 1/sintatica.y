%{
#include <iostream>
#include <string>
#include <sstream>

#define YYSTYPE atributos

using namespace std;

int qntdVariaveisTemp;

struct atributos
{
	string label;
	string traducao;
};

int yylex(void);
void yyerror(string);

string geraNomeTemp();

%}

%token TK_NUM TK_ID
%token FIM_LINHA
%start START

%left '+'

%%

START 	    :  COMANDOS
            {
                cout << $1.traducao << endl;
            }
            |
            ;

COMANDOS    : COMANDO COMANDOS
            {
                $$.traducao = $1.traducao + $2.traducao;
            }
            | // pq ele interpretaria como comandos nunca tendo um final
            {
                $$.traducao = "";
            }
            ;

COMANDO     : E FIM_LINHA
            | FIM_LINHA // precisa disso p caso de pegar mais enters sem nada
            {
                $$.traducao = "";
            }
            ;

E           : E '+' E
            {
                $$.label = geraNomeTemp();
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
                " = " + $1.label + " + " + $3.label + ";\n";
            }
            |
            TK_ID
            {
                $$.label = geraNomeTemp();
                $$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
            }
            |
            TK_NUM
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
    return "temp" + to_string(qntdVariaveisTemp);
}

int main( int argc, char* argv[] )
{
    int qntdVariaveisTemp = 0;

	yyparse();

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}				
