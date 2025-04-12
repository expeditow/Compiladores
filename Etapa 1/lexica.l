%{
    #include <string>
%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z]

DELIM {ESPACO}+
NUM {DIGITO}+
ID {LETRA}({LETRA}|{NUM})*

%%

"\n"        {}
{DELIM} 	{}


"main"		{ return TK_MAIN; }

"fn"        { return TK_FUNCAO; }
"->"        { return TK_IDENTIFICADOR_FUNCAO; } // pode se chamar assim?
"i16"       { return TK_INT_16; }


[(){}[\];,]	{ return *yytext; }

[+\-*/]		{ return *yytext; }

{NUM}		{ yylval.traducao = yytext; return TK_NUM; }
{ID}		{ yylval.label = yytext; return TK_ID; }

.			{}

%%