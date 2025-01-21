#include <stdio.h>

int larg(int T[], int size, int i, int max)
{
    if (i == size)
        return max;

    if (T[i] > max)
        return larg(T, size, i + 1, T[i]);
    else
        return larg(T, size, i + 1, max);
}

int main()
{
    int T[7] = {0, 1, 70, 1, 5, 25, 80};
    int size = 7;
    int max = T[0];

    int largest = larg(T, size, 0, max);

    printf("the largest is %d\n", largest);
    return 0;
}