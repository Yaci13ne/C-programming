// remove duplicate from an array

/*main idea : put all in another array passed by reference into the function "removed" */

#include <stdio.h>
#include <stdlib.h>

void removed(int *T, int *V, int N, int *newsize)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        int duplicate = 0;

        for (j = 0; j < *newsize; j++)
        {
            if (T[i] == V[j])
            {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate)
        {
            V[*newsize] = T[i];
            (*newsize)++;
        }
    }
}

int main()
{
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int T[N];

    for (int i = 0; i < N; i++)
    {
        printf("T[%d] = ", i);
        scanf("%d", &T[i]);
    }

    int V[N];
    int newsize = 0;
    removed(T, V, N, &newsize);

    printf("Array after removing duplicates:\n");
    for (int i = 0; i < newsize; i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n");

    return 0;
}
