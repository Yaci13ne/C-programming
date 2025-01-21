/* You are given two arrays of integers, V1 and V2. Your task is to write a program that performs the following operations:

--Check if the Arrays are Sorted: For each array (V1 and V2), check whether the elements are in ascending order.
--Sort the Arrays: If either array is not sorted, sort it in ascending order using the bubble sort algorithm.
--Combine the Arrays: Create a new array by combining V1 and V2, such that the elements of V1 come first, followed by the elements of V2.
--Check and Sort the Combined Array: After combining the arrays, check if the new array is sorted. If it is not, sort it.
--Display the Final Array: Finally, display the elements of the combined and sorted array.


Input:
Two integers N and M representing the number of elements in arrays V1 and V2, respectively.
Followed by N integers for the array V1 and M integers for the array V2.


Output:
The final sorted array after combining the two arrays.*/
#include <stdio.h>
#include <stdlib.h>

int isArraySorted(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0; // Change 2 to 0 for clearer representation
        }
    }
    return 1;
}

void mixage(int *V1, int *V2, int **mixed, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        (*mixed)[i] = V1[i];
    }
    for (int i = 0; i < M; i++)
    {
        (*mixed)[N + i] = V2[i];
    }
}

void readVec(int V[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("V[%d] = ", i);
        scanf("%d", &V[i]);
    }
}

void display(int *V, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("V[%d] = %d\n", i, *(V + i));
    }
}

void sorted(int **V, int size)
{
    int tmp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if ((*V)[j] < (*V)[i])
            {
                tmp = (*V)[i];
                (*V)[i] = (*V)[j];
                (*V)[j] = tmp;
            }
        }
    }
}

int main()
{
    int N, M;
    printf("Give number of elements of V1: ");
    scanf("%d", &N);
    printf("Give number of elements of V2: ");
    scanf("%d", &M);

    int *V1 = malloc(N * sizeof(int));
    int *V2 = malloc(M * sizeof(int));

    if (V1 == NULL || V2 == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter values of first array\n");

    readVec(V1, N);

    printf("Enter values of second array \n");
    readVec(V2, M);

    int check1 = isArraySorted(V1, N);
    int check2 = isArraySorted(V2, M);
    if (check1 == 0)
    {
        sorted(&V1, N);
    }
    if (check2 == 0)
    {
        sorted(&V2, M);
    }

    int sizem = N + M;

    int *mixed = malloc(sizem * sizeof(int));
    if (mixed == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    mixage(V1, V2, &mixed, N, M);

    int check3 = isArraySorted(mixed, sizem);
    if (check3 == 0)
    {
        sorted(&mixed, sizem);
    }

    printf("THE ARRAY AFTER MIXING : \n");
    display(mixed, sizem);

    free(V1);
    free(V2);
    free(mixed);

    return 0;
}
