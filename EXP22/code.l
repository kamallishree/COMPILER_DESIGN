%{
#include <stdio.h>
%}

%%
<[^>]+>    { printf("%s\n", yytext); }
.|\n       ;
%%

int main()
{
    FILE *fp = fopen("sample.html", "r");

    if(fp == NULL)
    {
        printf("Unable to open file\n");
        return 1;
    }

    yyin = fp;
    yylex();
    fclose(fp);

    return 0;
}

int yywrap()
{
    return 1;
}
