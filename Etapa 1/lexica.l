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

{DELIM} 	{}
"\n"        { return FIM_LINHA;}

[(){}[\];,]	{ return *yytext; }

[+\-*/]		{ return *yytext; }
[=]         { return *yytext; }
{NUM}		{ yylval.traducao = yytext; return TK_NUM; }
{ID}		{ yylval.label = yytext; return TK_ID; }


.			{}

%%