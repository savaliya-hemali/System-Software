
#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

int E();
int E1();
int T();
int T1();
int F();

int E()
{
    if (T())
        return E1();

    return 0;
}

int E1()
{
    if (input[pos] == '+')
    {
        pos++;
        if (T())
            return E1();
        return 0;
    }

    return 1;
}

int T()
{
    if (F())
        return T1();

    return 0;
}

int T1()
{
    if (input[pos] == '*')
    {
        pos++;
        if (F())
            return T1();
        return 0;
    }

    return 1;
}

int F()
{
    if (input[pos] == 'i')
    {
        pos++;
        return 1;
    }

    if (input[pos] == '(')
    {
        pos++;

        if (E() && input[pos] == ')')
        {
            pos++;
            return 1;
        }
    }

    return 0;
}

int main()
{
    printf("Enter input string: ");
    scanf("%99s", input);

    if (E() && input[pos] == '\0')
        printf("String is Accepted.\n");
    else
        printf("String is Rejected.\n");

    return 0;
}

/*
Enter input string: i+i*i
String is Accepted.

Enter input string: i+*i
String is Rejected.
*/