#include <stdio.h>
#include <string.h>

int ispali(char S[], int start, int end)
{
    if (start >= end)
        return 1;

    if (S[start] != S[end])
        return 0;

    return ispali(S, start + 1, end - 1);
}

int main()
{
    char S[100];
    printf("Enter the word: ");
    gets(S);

    int size = strlen(S);
    printf("%d", size);

    int cmp = ispali(S, 0, size - 1);

    if (cmp)
        printf("palindrome");

    else
        printf("not palindrome");

    return 0;
}
