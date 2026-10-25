
#include <stdio.h>
#include <string.h>

int main()
{
    char nt, alpha[50], beta[50];

    printf("Enter the non-terminal: ");
    scanf(" %c", &nt);

    printf("Enter alpha (after %c): ", nt);
    scanf("%s", alpha);

    printf("Enter beta: ");
    scanf("%s", beta);

    if (alpha[0] == nt)
    {
        printf("\nGrammar after removing Left Recursion:\n");
        printf("%c -> %s%c'\n", nt, beta, nt);
        printf("%c' -> %s%c' | epsilon\n", nt, alpha + 1, nt);
    }
    else
    {
        printf("\nThe given grammar does not have immediate left recursion.\n");
    }

    return 0;
}

/*
Enter the non-terminal: A
Enter alpha (after A): Aa
Enter beta: b
Grammar after removing Left Recursion:
A -> bA'
A' -> aA' | epsilon

*/