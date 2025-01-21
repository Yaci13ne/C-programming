#include <stdio.h>
#include <stdlib.h>

int nelements(char S[], int i, int cmp)
{
    if (S[i] == '\0')
        return cmp;

    else
        return nelements(S, i + 1, cmp + 1);
}

int main()
{
    char S[] = {"hello"};

    int result = nelements(S, 0, 0);
    printf("%d", result);
}
