#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void printarray(int T[], int size, int i)
{

    if (i == size)
        return;
    printarray(T, size, i + 1);
    printf("%d: %d\n", i, T[i]);
}

int main()
{
    int T[7] = {0, 1, 0, 1, 5, 30, 30};

    printarray(T, 7, 0);
}