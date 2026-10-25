#include <stdio.h>
#include <stdlib.h>

char input[100];
int pos = 0;

int E();
int T();
int F();

int E()
{
    if (T())
    {
        if (input[pos] == '+')
        {
            pos++;
            if (E())
                return 1;
            return 0;
        }
        return 1;
    }
    return 0;
}

int T()
{
    if (F())
    {
        if (input[pos] == '*')
        {
            pos++;
            if (T())
                return 1;
            return 0;
        }
        return 1;
    }
    return 0;
}

int F()
{
    if (input[pos] == 'i')
    {
        pos++;
        return 1;
    }
    else if (input[pos] == '(')
    {
        pos++;
        if (E())
        {
            if (input[pos] == ')')
            {
                pos++;
                return 1;
            }
        }
        return 0;
    }
    return 0;
}

int main()
{
    printf("Enter the input string: ");
    scanf("%99s", input);

    if (E() && input[pos] == '\0')
        printf("String is Accepted.\n");
    else
        printf("String is Rejected.\n");

    return 0;
}
/*
Enter the input string: i+i*i
String is Accepted.

Enter the input string: i+*i
String is Rejected.

*/