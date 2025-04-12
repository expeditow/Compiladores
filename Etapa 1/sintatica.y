%{
#include <iostream>
#include <string>
#include <sstream>

#define YYSTYPE atributos

using namespace std;

struct atributos
{
	string label;
	string traducao;
};

int yylex(void);
void yyerror(string);

int contVariaveis = 0;

string nomeiaVariavelTemporaria(){
    contVariaveis++;
    return "t" + to_string(contVariaveis);
}

%}

%token TK_IDENTIFICADOR_FUNCAO
%token TK_NUM
%token TK_MAIN TK_ID TK_INT_16 TK_FUNCAO

%start S

%left '+'

%%

S 			: TK_FUNCAO TK_MAIN '(' ')' BLOCO // como eu posso colocar um parâmetro opcional aqui?
			{
				cout << "/*Compilador Cria*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n" <<  "void main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
			}
            | TK_FUNCAO TK_MAIN '(' ')' TK_IDENTIFICADOR_FUNCAO TIPO BLOCO
            {
                cout << "/*Compilador Cria*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n" << $6.traducao <<" main(void)\n{\n" << $7.traducao << "\treturn 0;\n}" << endl; 
            }
			;
TIPO        : TK_INT_16
            {
                $$.traducao = "int";
            }

BLOCO		: '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
			}
			;

COMANDOS	: COMANDO COMANDOS
			|
			;

COMANDO 	: E ';'
			;

E 			: E '+' E
			{
				$$.traducao = $1.traducao + $3.traducao + "\ta = b + c;\n";
			}
			| TK_NUM
			{
				$$.traducao = "\ta = " + $1.traducao + ";\n";
			}
			| TK_ID
			;

%%

#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	yyparse();

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}				
