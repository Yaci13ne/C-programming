
#include <stdio.h>
#include <stdlib.h>

void readarr(int *arr, int n)
{
    printf("Enter values for the array:\n");
    for (int *ptr = arr; ptr < arr + n; ptr++)
    {
        printf("V[%ld] = ", ptr - arr + 1);
        scanf("%d", ptr);
    }
}

void deleteZeroes(int *arr, int *n)
{
    int count = 0;
    for (int i = 0; i < *n; i++)
    {
        if (arr[i] != 0)
        {
            arr[count++] = arr[i];
        }
    }
    *n = count; // Update n to the new size of the array
}

int main()
{
    int n;
    printf("Enter how many values of array:");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    readarr(arr, n);

    printf("Array before deletion:\n[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");

    deleteZeroes(arr, &n);

    printf("Array after deletion of zeroes:\n[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");

    free(arr);

    return 0;
}
