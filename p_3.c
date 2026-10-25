
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[50], s2[50], prefix[50];
    int i = 0, j = 0;

    printf("Enter first production: ");
    scanf("%s", s1);

    printf("Enter second production: ");
    scanf("%s", s2);

    // Find common prefix
    while (s1[i] != '\0' && s2[i] != '\0' &&
           s1[i] == s2[i])
    {
        prefix[i] = s1[i];
        i++;
    }

    prefix[i] = '\0';

    if (i == 0)
    {
        printf("\nNo left factoring required.\n");
    }
    else
    {
        printf("\nAfter Left Factoring:\n");

        printf("A -> %sA'\n", prefix);

        printf("A' -> %s | %s\n", s1 + i, s2 + i);
    }

    return 0;
}

/*  Enter first production: abc
//Enter second production: abd

After Left Factoring:
A -> abA'
A' -> c | d  */