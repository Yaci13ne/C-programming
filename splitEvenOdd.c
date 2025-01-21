
#include <stdio.h>
#include <stdlib.h>

void readVec(int V[], int N)
{

    for (int *p = V; p < N + V; p++)
    {

        scanf("%d", (p));
    }
}

void display(int *V, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("V[%d] = %d\n", i, *(V + i));
    }
}

void evenodd(int *V, int N, int *even, int *odd, int **V1, int **V2)
{
    *even = 0;
    *odd = 0;
    for (int i = 0; i < N; i++)
    {
        if (V[i] % 2 == 0)
            (*even)++;
        else
            (*odd)++;
    }

    *V1 = malloc((*odd) * sizeof(int));
    *V2 = malloc((*even) * sizeof(int));

    int cmptr = 0, cmp = 0;
    for (int i = 0; i < N; i++)
    {
        if (V[i] % 2 == 0)
            (*V1)[cmptr++] = V[i];
        else
            (*V2)[cmp++] = V[i];
    }
}

int main()
{
    int N;
    printf("Give number of elements: ");
    scanf("%d", &N);

    int V[N], *V1 = NULL, *V2 = NULL;
    int even = 0, odd = 0;

    readVec(V, N);
    evenodd(V, N, &even, &odd, &V1, &V2);

    printf("Even numbers:\n");
    display(V1, even);
    printf("\nOdd numbers:\n");
    display(V2, odd);

    free(V1);
    free(V2);

    return 0;
}
