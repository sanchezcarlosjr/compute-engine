%option noyywrap batch

%{
int chars = 0;
%}

%%
[a-z]      {
            /* count the spaces */
            chars++;
        }
. {}
%%

void analyze(const char* in)  {
	chars = 0;
	YY_BUFFER_STATE bp = yy_scan_string(in);  // Creates a buffer from the string
	yy_switch_to_buffer(bp);                   // Use the buffer
	int ret = yylex();                       // Parse the string
	yy_delete_buffer(bp);                      // Free the buffer
}

int get_chars() {
   return chars;
}

