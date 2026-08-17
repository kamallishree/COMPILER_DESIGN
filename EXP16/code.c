#include <stdio.h>
#include <string.h>

int main()
{
    char op1[20], op2[20], result[20], op;
    int n, i;

    printf("Enter number of three address statements: ");
    scanf("%d", &n);

    printf("\nEnter statements in the form: result operand1 operator operand2\n");

    for (i = 0; i < n; i++)
    {
        scanf("%s %s %c %s", result, op1, &op, op2);

        printf("\nMOV R0, %s\n", op1);

        switch (op)
        {
            case '+':
                printf("ADD R0, %s\n", op2);
                break;

            case '-':
                printf("SUB R0, %s\n", op2);
                break;

            case '*':
                printf("MUL R0, %s\n", op2);
                break;

            case '/':
                printf("DIV R0, %s\n", op2);
                break;

            default:
                printf("Invalid operator\n");
        }

        printf("MOV %s, R0\n", result);
    }

    return 0;
}
