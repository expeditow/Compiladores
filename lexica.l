%{
    #include <string>
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

"\n"        { return FIM_LINHA;}

[(){}[\];,]	{ return *yytext; }

[+\-*/]		{ return *yytext; }

"="         { return *yytext;}

"nmr"         { yylval.label = yytext; return TK_TIPO; }



{NUM}		{ yylval.traducao = yytext; return TK_INT;  }
{REAL}		{ yylval.traducao = yytext; return TK_FLOAT;}

{ID}		{ yylval.label = yytext; return TK_ID; }


.			{}

%%