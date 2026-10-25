
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char postfix[100], stack[100];
    char op, arg1, arg2, result;
    int top = -1, temp = 1, i;

    printf("Enter postfix expression: ");
    scanf("%99s", postfix);

    printf("\nOperator\tArg1\tArg2\tResult\n");

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isalnum((unsigned char)postfix[i]))
        {
            stack[++top] = postfix[i];
        }
        else
        {
            op = postfix[i];

            if (top < 1)
            {
                printf("Invalid postfix expression!\n");
                return 1;
            }

            arg2 = stack[top--];
            arg1 = stack[top--];

            result = 'T' + temp - 1;
            temp++;

            printf("%c\t\t%c\t%c\t%c\n",
                   op, arg1, arg2, result);

            stack[++top] = result;
        }
    }

    if (top != 0)
        printf("\nInvalid postfix expression!\n");
    else
        printf("\nQuadruple table generated successfully.\n");

    return 0;
}

/*
Enter postfix expression: ab+c*

Operator    Arg1    Arg2    Result
+           a       b       T
*           T       c       U

Quadruple table generated successfully.
*/