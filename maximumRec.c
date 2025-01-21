// find the maximum of an array

#include <stdio.h>
#include <stdlib.h>

int maxii(int T[], int N, int i, int max)
{
    if (i == N)
        return max;
    if (T[i] > max)
        return maxii(T, N, i + 1, T[i]);
    else
        return maxii(T, N, i + 1, max);
}

int main()
{
    int T[10] = {0, 5, 5, 9, 88, 5, 666, 9, 8, 145};

    int max = T[0];
    for (int i = 0; i < 10; i++)
    {
        if (max < T[i])
            max = T[i];
    }

    int maximum = maxii(T, 10, 0, T[0]);
    printf("the maximum is : %d", maximum);
}
