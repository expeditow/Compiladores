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
TIPO_SIMBOLO getVariavelTabelaSimbolos(string nome);
void printTabelaSimbolos();
string insereTabelaSimbolos(string nome, string tipo);
string geraNomeTemp(string tipo);
string getTipo(string tipo);
string infereTipo(string tipo1, string tipo2);
string getBooleano(string valor);


#define true 1
#define false 0

%}

%token TK_TIPO TK_ID
%token TK_INT TK_FLOAT TK_BOOLEAN TK_CHAR
%token TK_MAIOR_IGUAL TK_MENOR_IGUAL TK_DIFERENTE TK_IGUAL TK_E_LOGICO TK_OU_LOGICO TK_NEGACAO
%token FIM_LINHA

%start START


%%

START 	    :  CMDS
            {   
                string defines = "\t#define true 1\n\t#define false 0\n\n\n";
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
                $$.traducao = $3.traducao + "\t" + temp.label + " = " + $3.label + ";\n";

                // Tem que ver, pq nos exemplos dele ele deixa uma variável tmeporária para receber atribuições e após isso
                // ele aplica na variável, é simples fazer isso, só usa temporária e acabou
            }
        

EXP         : EXP '+' TERMO 
            {   
                $$.tipo = infereTipo($1.tipo, $3.tipo);
                $$.label = insereTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao;

                if($1.tipo == "int" && $3.tipo == "float") 
                {
                    string temporario = insereTabelaSimbolos("","float");
                    $$.traducao += "\t" + temporario + " = (float) " + $1.label + ";\n" +
                    "\t" + $$.label + " = " + temporario + " + " + $3.label + ";\n"; 

                }
                else if($1.tipo == "float" && $3.tipo == "int") 
                {
                    string temporario = insereTabelaSimbolos("","float");
                    $$.traducao += "\t" + temporario + " = (float) " + $3.label + ";\n" + 
                    "\t" + $$.label + " = " + $1.label + " + " + temporario + ";\n"; 
                }
                else 
                {
                    $$.traducao += $1.traducao + $3.traducao + "\t" + 
                    $$.label + " = " + $1.label + " + " + $3.label + ";\n";
                }
            }
            | EXP '-' TERMO 
            {   
                $$.tipo = infereTipo($1.tipo, $3.tipo);
                $$.label = insereTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao;
                
                if($1.tipo == "int" && $3.tipo == "float") 
                {
                    string temporario = insereTabelaSimbolos("","float");
                    $$.traducao += "\t" + temporario + " = (float) " + $1.label + ";\n" +
                    "\t" + $$.label + " = " + temporario + " - " + $3.label + ";\n"; 

                }
                else if($1.tipo == "float" && $3.tipo == "int") 
                {
                    string temporario = insereTabelaSimbolos("","float");
                    $$.traducao += "\t" + temporario + " = (float) " + $3.label + ";\n" + 
                    "\t" + $$.label + " = " + $1.label + " - " + temporario + ";\n"; 
                }
                else 
                {
                    $$.traducao = $1.traducao + $3.traducao + "\t" + 
                    $$.label + " = " + $1.label + " - " + $3.label + ";\n";
                }
            }
            | EXP '>' TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " > " + $3.label + ";\n";
            }
            | EXP '<' TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " < " + $3.label + ";\n";
            }
            | EXP TK_MAIOR_IGUAL TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " >= " + $3.label + ";\n";
            }
            | EXP TK_MENOR_IGUAL TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + "<= " + $3.label + ";\n";
            }
            | EXP TK_DIFERENTE TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " != " + $3.label + ";\n";           
            }
            | EXP TK_IGUAL TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " == " + $3.label + ";\n";           
            }
            | EXP TK_E_LOGICO TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " && " + $3.label + ";\n";  
            }
            | EXP TK_OU_LOGICO TERMO 
            {
                $$.tipo = "bool";
                $$.label = insereTabelaSimbolos("", $$.tipo);
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " || " + $3.label + ";\n";  
            }
            | TERMO         
            { 
                $$.label = $1.label;
                $$.traducao = $1.traducao;
                $$.tipo = $1.tipo;      
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
                $$.tipo = temp.tipoVariavel;
            }
            ;

TERMO       : TERMO '*' FATOR 
            {   
                $$.tipo = infereTipo($1.tipo, $3.tipo);
                $$.label = insereTabelaSimbolos("",  $$.tipo);
                $$.traducao = $1.traducao + $3.traducao +
                "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
            }
            | TERMO '/' FATOR 
            { 
                $$.tipo = infereTipo($1.tipo, $3.tipo);
                $$.label = insereTabelaSimbolos("",  $$.tipo);
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
                // Não entendi muito bem, mas vou fazer uma variável a mais só p deixar da forma como ele fez
                // temos que criar duas variáveis pq n podemos mod

                $$.label = insereTabelaSimbolos("", $2.label);
                string tempBr = insereTabelaSimbolos("", $2.label);

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
                    temp = getVariavelTabelaSimbolos($1.label);
                
                $$.label = temp.label;
                $$.traducao = "";
                $$.tipo = temp.tipoVariavel;
            }
            | TK_NEGACAO TK_ID
            {
                 $$.tipo = "bool";

                TIPO_SIMBOLO temp;
                if(!verificaTabelaSimbolos($2.label))
                    yyerror("Não foi inicializado uma das variáveis");
                else 
                    temp = getVariavelTabelaSimbolos($2.label);

                $$.label = insereTabelaSimbolos("", $$.tipo);
                 $$.traducao = "\t" + $$.label + " = !" + temp.label + ";\n";
            }
            | TK_INT
            { 
                $$.label = insereTabelaSimbolos("", "nmr");
                $$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
                $$.tipo = "int"; 
            }
            | TK_FLOAT
            {   
                $$.label = insereTabelaSimbolos("", "ncv");
                $$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n"; 
                $$.tipo = "float"; 
            }
            | TK_BOOLEAN
            {
                $$.label = insereTabelaSimbolos("", "pp");
                string valor = getBooleano($1.label);

                if(valor == "error") yyerror("Valor atribuído de forma errada!");

                $$.traducao = "\t" + $$.label + " = " + valor + ";\n";
                $$.tipo = "bool"; 
            }
            | TK_CHAR
            {
                $$.label = insereTabelaSimbolos("", "letra");
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
string insereTabelaSimbolos(string nome, string tipo)
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
string getTipo(string tipo) 
{
    if(tipo == "nmr" || tipo == "int")
        return "int";
    else if(tipo == "ncv" || tipo == "float")
        return "float";
    else if(tipo == "letra" || tipo == "char")
        return "char";
    else if(tipo == "pp" || tipo == "bool")
        return "int";
    else 
        return "null";    
}

string infereTipo(string tipo1, string tipo2) // Tabela de conversão que ele acabou falando 
{
    if(tipo1 == "int" && tipo1 == tipo2) return "int";
    else return "float";
}

string getBooleano(string valor)
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
	cout << MSG << endl;
	exit (0);
}				

/*

Pontos legais de se fazer após ter a base da linguagem (toda a etapa 1)

    - separar duas funções p inserir na tabela de símbolos
    - variáveis declaradas
    - variáveis temporárias

Criar variáveis para facilitar leitura de algumas definições nossa na linguagem - no nosso código aqui no caso

Testar se o valor atribuído a um id, bate com o seu valor

Organizar e nomear melhor funções
Refatorar o uso de strings mágicas

Garantir que os tipos só podem receber coisas deles mesmos, ou tem que fazer conversão algo assim

Tratar a prioridade nos operadores lógicos

Garantir que os operadores lógicos só atuem entre os booleanos na minha linguagem - RELACIONAIS E LÓGICOS
    - Logicamente que vou ter que tratar mais exceções além dessa
    - Fazer com que eles não formem expressão também! apenas dois elementos podem ser comparados 
        - Isso seria interresante
            - P isso eu acho que daria p criar uma variável no nó que diz quantos elementos estão na expressão
            - Ai caso o nó que estamos seja um que suporte apenas dois elementos, retornamos erro, seria uma das formas de fazer
            - Verificar se as variáveis possuem valor também

*/