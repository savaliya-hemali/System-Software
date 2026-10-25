
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char input[200];
    char token[50];
    int i = 0, j;

    printf("Enter a statement: ");
    fgets(input, sizeof(input), stdin);

    printf("\nToken\t\tType\n");
    printf("-------------------------\n");

    while (input[i] != '\0')
    {
        // Ignore spaces and newline
        if (isspace((unsigned char)input[i]))
        {
            i++;
            continue;
        }

        // Identify identifiers and keywords
        if (isalpha((unsigned char)input[i]) || input[i] == '_')
        {
            j = 0;

            while (isalnum((unsigned char)input[i]) ||
                   input[i] == '_')
            {
                token[j++] = input[i++];
            }

            token[j] = '\0';

            if (strcmp(token, "int") == 0 ||
                strcmp(token, "float") == 0 ||
                strcmp(token, "char") == 0 ||
                strcmp(token, "if") == 0 ||
                strcmp(token, "else") == 0 ||
                strcmp(token, "while") == 0 ||
                strcmp(token, "for") == 0 ||
                strcmp(token, "return") == 0)
            {
                printf("%s\t\tKeyword\n", token);
            }
            else
            {
                printf("%s\t\tIdentifier\n", token);
            }
        }

        // Identify constants
        else if (isdigit((unsigned char)input[i]))
        {
            j = 0;

            while (isdigit((unsigned char)input[i]))
            {
                token[j++] = input[i++];
            }

            token[j] = '\0';
            printf("%s\t\tConstant\n", token);
        }

        // Identify operators
        else if (strchr("+-*/%=<>!", input[i]) != NULL)
        {
            printf("%c\t\tOperator\n", input[i]);
            i++;
        }

        // Identify special symbols
        else
        {
            printf("%c\t\tSpecial Symbol\n", input[i]);
            i++;
        }
    }

    return 0;
}

/*
input :
int a = 10 + b;

opt put:
Token           Type
-------------------------
int             Keyword
a               Identifier
=               Operator
10              Constant
+               Operator
b               Identifier
;               Special Symbol
*/