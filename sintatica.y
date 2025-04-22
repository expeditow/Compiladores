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

string geraNomeTemp(string tipo);


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
                TIPO_SIMBOLO temp;
                temp.nomeVariavel = $2.label;
                temp.tipoVariavel = $1.label;
                temp.label = geraNomeTemp($1.label);
                tabelaSimbolos.push_back(temp);
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
                $$.traducao = $3.traducao + "\t" + temp.label + " = " + $3.label + ";\n";
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
    else // caso em que n tenha nenhum tipo atribuído
    {
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "void"});
    }

    return "T" + to_string(qntdVariaveisTemp);
}

/*string insereTabelaSimbolos(string nome)    // vai retonar a variável temporária atribuída
{   
    string labelTemp = geraNomeTemp("");
    tabelaSimbolos.push_back(temp);
    return geraNomeTemp("");
}*/

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
        cout << "Simbolo [" <<  i+1 << "] : " <<  tabelaSimbolos[i].nomeVariavel << " " 
        << tabelaSimbolos[i].tipoVariavel << " " << tabelaSimbolos[i].label << endl;

    }
    cout << endl;
}

int main( int argc, char* argv[] )
{   
    int qntdVariaveisTemp = 0;

	yyparse();

    //printTabelaSimbolos(); - fins depurativos

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}				
