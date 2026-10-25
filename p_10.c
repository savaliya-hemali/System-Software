
#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

int type();
int simple();

int match(char *token)
{
    int len = strlen(token);

    if (strncmp(input + pos, token, len) == 0 &&
        (input[pos + len] == ' ' ||
         input[pos + len] == '\0' ||
         input[pos + len] == '[' ||
         input[pos + len] == ']'))
    {
        pos += len;

        while (input[pos] == ' ')
            pos++;

        return 1;
    }

    return 0;
}

int simple()
{
    int save = pos;

    if (match("integer"))
        return 1;

    pos = save;

    if (match("char"))
        return 1;

    pos = save;

    if (match("num"))
    {
        if (match("dotdot"))
        {
            if (match("num"))
                return 1;
        }
    }

    return 0;
}

int type()
{
    int save = pos;

    if (simple())
        return 1;

    pos = save;

    if (match("^"))
    {
        if (match("id"))
            return 1;
    }

    pos = save;

    if (match("array"))
    {
        if (match("["))
        {
            if (simple())
            {
                if (match("]"))
                {
                    if (match("of"))
                    {
                        if (type())
                            return 1;
                    }
                }
            }
        }
    }

    return 0;
}

int main()
{
    printf("Enter the input string (use spaces between tokens):\n");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    if (type())
    {
        while (input[pos] == ' ')
            pos++;

        if (input[pos] == '\0')
            printf("String is Accepted.\n");
        else
            printf("String is Rejected.\n");
    }
    else
    {
        printf("String is Rejected.\n");
    }

    return 0;
}

/*
Input: integer
Output:String is Accepted.

Input: array [ integer ] of char
Output:String is Accepted.

Input:array [ integer ] char
Output :String is Rejected.

*/