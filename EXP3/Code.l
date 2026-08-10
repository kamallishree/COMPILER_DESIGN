%{
#include <stdio.h>
%}

%x COMMENT

%%
[ \t\n]+                    ;

"//".*                      ;

"/*"                        { BEGIN(COMMENT); }

<COMMENT>"*/"               { BEGIN(INITIAL); }

<COMMENT>\n                 ;

<COMMENT>.                  ;

[a-zA-Z_][a-zA-Z0-9_]*       { printf("Identifier : %s\n", yytext); }

[0-9]+                      { printf("Constant   : %s\n", yytext); }

[+\-*/=]                    { printf("Operator   : %s\n", yytext); }

.                           { printf("Symbol     : %s\n", yytext); }
%%

int main()
{
    printf("Enter the input:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
