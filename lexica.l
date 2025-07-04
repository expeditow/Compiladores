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

\n        { yylinha++; return FIM_LINHA;}

[(){}[\];,]	{ return *yytext; }
[+\-*/]		{ return *yytext; }
"++"        { return TK_INCREMENTO; }
"--"        { return TK_DECREMENTO; }
":"         { return *yytext; }

{NUM}		{ yylval.traducao = yytext;  yylval.label   = yytext; return TK_INT;  }
{REAL}		{ yylval.traducao = yytext; yylval.label = yytext; return TK_FLOAT;}

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
"+="        { return TK_MAIS_IGUAL;  }
"-="        { return TK_MENOS_IGUAL; }
"*="        { return TK_MULT_IGUAL;  }
"/="        { return TK_DIV_IGUAL;   }
"**"        { return TK_POTENCIA; } 

"toma"      { return TK_RETURN; }
"nmr"       { yylval.label = yytext; return TK_TIPO; }
"ncv"       { yylval.label = yytext; return TK_TIPO; }
"pp"        { yylval.label = yytext; return TK_TIPO; }
"letra"     { yylval.label = yytext; return TK_TIPO; }    
"falada"    { yylval.label = yytext; return TK_TIPO; } 


\'[^\\']\'  { yylval.traducao = yytext; return TK_CHAR; }
\"[^\"]*\"  { yylval.traducao = yytext; return TK_STRING; }

"se"        { return TK_IF;}
"senao"     { return TK_ELSE; }
"ainda"     { return TK_WHILE; }
"mantem"    { return TK_DO; }
"corre"     { return TK_FOR; }
"em"        { return TK_IN; }

"pega"      { return TK_SWITCH; }
"visao"     { return TK_CASE; }
"pare"      { return TK_BREAK;  } 
"padrao"    { return TK_DEFAULT; } 
"continua"  { return TK_CONTINUE; }

"ouve"      { return TK_SCAN; }
"fala"      { return TK_PRINT; }
"reto"      { yylval.label = yytext; return TK_BOOLEAN; }
"torto"     { yylval.label = yytext; return TK_BOOLEAN; }
{ID}		{ yylval.label = yytext; return TK_ID; }


.			{}

%%