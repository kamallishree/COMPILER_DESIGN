#include <stdio.h>
#include <string.h>
#include <ctype.h>

char expr[100];
char stack[100];
int top = -1;
int temp = 1;

int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

void generate()
{
    int i;
    char a, b, op;
    char t1[10], t2[10];

    for (i = 0; expr[i] != '\0'; i++)
    {
        if (isalnum(expr[i]))
        {
            stack[++top] = expr[i];
        }
        else if (expr[i] == '(')
        {
            stack[++top] = expr[i];
        }
        else if (expr[i] == ')')
        {
            while (top >= 0 && stack[top] != '(')
            {
                op = stack[top--];
                b = stack[top--];
                a = stack[top--];

                printf("t%d = %c %c %c\n", temp, a, op, b);
                stack[++top] = '0' + temp;
                temp++;
            }
            top--;
        }
        else
        {
            while (top >= 0 &&
                   precedence(stack[top]) >= precedence(expr[i]))
            {
                op = stack[top--];
                b = stack[top--];
                a = stack[top--];

                printf("t%d = %c %c %c\n", temp, a, op, b);
                stack[++top] = '0' + temp;
                temp++;
            }

            stack[++top] = expr[i];
        }
    }

    while (top >= 0)
    {
        op = stack[top--];
        b = stack[top--];
        a = stack[top--];

        printf("t%d = %c %c %c\n", temp, a, op, b);
        stack[++top] = '0' + temp;
        temp++;
    }
}

int main()
{
    printf("Enter expression: ");
    scanf("%s", expr);

    printf("\nThree Address Code:\n");
    generate();

    return 0;
}
