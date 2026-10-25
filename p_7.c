/*
creat input.txt and Keep input.txt and practical_9.c in the same folder.
START 100
MOVER AREG, ='5'
MOVEM AREG, X
ADD AREG, ='1'
MOVEM AREG, Y
X DC 10
Y DS 1
END
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char line[100], label[20], opcode[20], operand[20];
    char symtab[20][20], littab[20][20];
    int symaddr[20], litaddr[20];
    int sc = 0, lc = 0, lcValue = 0;
    int i;

    fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening input.txt\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp))
    {
        label[0] = opcode[0] = operand[0] = '\0';

        int count = sscanf(line, "%19s %19s %19s",
                           label, opcode, operand);

        if (count <= 0)
            continue;

        if (strcmp(label, "START") == 0)
        {
            lcValue = atoi(opcode);
            continue;
        }

        if (strcmp(label, "END") == 0)
            break;

        if (strcmp(label, "MOVER") != 0 &&
            strcmp(label, "MOVEM") != 0 &&
            strcmp(label, "ADD") != 0 &&
            strcmp(label, "SUB") != 0 &&
            strcmp(label, "MULT") != 0 &&
            strcmp(label, "DIV") != 0 &&
            strcmp(label, "DC") != 0 &&
            strcmp(label, "DS") != 0)
        {
            strcpy(symtab[sc], label);
            symaddr[sc++] = lcValue;
        }

        if (strcmp(label, "DC") == 0 ||
            strcmp(opcode, "DC") == 0)
        {
            lcValue++;
        }
        else if (strcmp(label, "DS") == 0 ||
                 strcmp(opcode, "DS") == 0)
        {
            lcValue++;
        }
        else
        {
            char *p = strchr(line, '=');

            if (p != NULL)
            {
                char literal[20];
                int j = 0;

                while (*p && *p != ',' && *p != '\n')
                    literal[j++] = *p++;

                literal[j] = '\0';

                int found = 0;

                for (i = 0; i < lc; i++)
                {
                    if (strcmp(littab[i], literal) == 0)
                        found = 1;
                }

                if (!found)
                {
                    strcpy(littab[lc], literal);
                    litaddr[lc++] = -1;
                }
            }

            lcValue++;
        }
    }

    fclose(fp);

    printf("\nSYMBOL TABLE (SYMTAB)\n");
    printf("Symbol\tAddress\n");

    for (i = 0; i < sc; i++)
        printf("%s\t%d\n", symtab[i], symaddr[i]);

    printf("\nLITERAL TABLE (LITTAB)\n");
    printf("Literal\tAddress\n");

    for (i = 0; i < lc; i++)
        printf("%s\t%d\n", littab[i], litaddr[i]);

    return 0;
}

/*
out put :
Symbol	Address
X	105
Y	106

LITTAB
Literal	Address
='5'	107
='1'	108
*/