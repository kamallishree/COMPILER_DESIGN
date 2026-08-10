%{
#include <stdio.h>
%}

%x COMMENT

%%
"//".*                      { printf("Single-line Comment\n"); }

"/*"                        { BEGIN(COMMENT); }

<COMMENT>"*/"               { BEGIN(INITIAL); printf("Multi-line Comment\n"); }

<COMMENT>\n                 ;

<COMMENT>.                  ;

.*                          { printf("Not a Comment\n"); }
\n                          ;
%%

int main()
{
    printf("Enter a comment:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
