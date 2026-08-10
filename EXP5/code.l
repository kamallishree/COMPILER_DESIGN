%{
#include <stdio.h>

int spaces = 0;
int newlines = 0;
%}

%%
[ \t]+      { spaces += yyleng; }
\n          { newlines++; }
.           { }
%%

int main()
{
    printf("Enter the text:\n");
    yylex();

    printf("\nNumber of whitespaces = %d\n", spaces);
    printf("Number of newline characters = %d\n", newlines);

    return 0;
}

int yywrap()
{
    return 1;
}
