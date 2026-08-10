%{
#include <stdio.h>
%}

%%
[ \t\n]+       ;

"+"             { printf("%s : Valid Arithmetic Operator\n", yytext); }
"-"             { printf("%s : Valid Arithmetic Operator\n", yytext); }
"*"             { printf("%s : Valid Arithmetic Operator\n", yytext); }
"/"             { printf("%s : Valid Arithmetic Operator\n", yytext); }

.               { printf("%s : Invalid Operator\n", yytext); }
%%

int main()
{
    printf("Enter operators:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
