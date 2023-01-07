%option noyywrap batch

%{
#include "parser.c"
%}

%%
[ \t]	;
[0-9]+\.[0-9]+ 	{yylval.fval = atof(yytext); return T_FLOAT;}
[0-9]+		{yylval.ival = atoi(yytext); return T_INT;}
\n		{return T_NEWLINE;}
"+"		{return T_PLUS;}
"-"		{return T_MINUS;}
"*"		{return T_MULTIPLY;}
"/"		{return T_DIVIDE;}
"("		{return T_LEFT;}
")"		{return T_RIGHT;}
. {}
%%

float analyze(const char* in)  {
	YY_BUFFER_STATE bp = yy_scan_string(in);
	yy_switch_to_buffer(bp);
	int ret = yyparse();
	yy_delete_buffer(bp);
	return get_result();
}