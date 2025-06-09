%{
    #include <string>
    int yylinha = 1;
%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z]

DELIM {ESPACO}+
REAL {NUM}+("."{NUM}+)?
NUM {DIGITO}+
ID {LETRA}({LETRA}|{NUM})*

%%


{DELIM} 	{}

"\n"        { yylinha++; return FIM_LINHA;}

[(){}[\];,]	{ return *yytext; }
[+\-*/]		{ return *yytext; }


{NUM}		{ yylval.traducao = yytext; return TK_INT; }
{REAL}		{ yylval.traducao = yytext; return TK_FLOAT;}

"elog"      { return TK_E_LOGICO; }
"&&"        { return TK_E_LOGICO; }
"oulog"     { return TK_OU_LOGICO; }
"||"        { return TK_OU_LOGICO; }
"nao"       { return TK_NEGACAO; }
"!"         { return TK_NEGACAO; }

"="         { return *yytext; }
[><!]       { return *yytext; }
">="        { return TK_MAIOR_IGUAL; }
"<="        { return TK_MENOR_IGUAL; }
"!="        { return TK_DIFERENTE;   }
"=="        { return TK_IGUAL;       }

"nmr"       { yylval.label = yytext; return TK_TIPO; }
"ncv"       { yylval.label = yytext; return TK_TIPO; }
"pp"        { yylval.label = yytext; return TK_TIPO; }
"letra"     { yylval.label = yytext; return TK_TIPO; }     


\'[^\\']\'  { yylval.traducao = yytext; return TK_CHAR; }

"se"        { return TK_IF;}
"reto"      { yylval.label = yytext; return TK_BOOLEAN; }
"torto"     { yylval.label = yytext; return TK_BOOLEAN; }
{ID}		{ yylval.label = yytext; return TK_ID; }


.			{}

%%