#include <stdio.h>
#include <stdlib.h>

int *readMatrix(int N, int M)
{
    int *matrix = (int *)malloc(N * M * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("M(%d,%d)=", i, j);
            scanf("%d", &matrix[i * M + j]);
        }
        printf("\n");
    }

    return matrix;
}

void printMatrix(int *matrix, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d\t", matrix[i * M + j]);
        }
        printf("\n");
    }
}

void statistics(int *matrix, int N, int M, int *min, int *max, int *mean)
{
    *min = matrix[0]; // Initialize min with the first element
    *max = matrix[0]; // Initialize max with the first element
    int sum = 0;
    int count = N * M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (matrix[i * M + j] < *min)
            {
                *min = matrix[i * M + j];
            }
            if (matrix[i * M + j] > *max)
            {
                *max = matrix[i * M + j];
            }
            sum += matrix[i * M + j];
        }
    }

    *mean = sum / count;
}

int main()
{
    int N, M;
    printf("Give me number of rows of the matrix: ");
    scanf("%d", &N);
    printf("Give me number of columns of the matrix: ");
    scanf("%d", &M);

    int min, max, mean;
    int *matrix = readMatrix(N, M);
    printMatrix(matrix, N, M);
    statistics(matrix, N, M, &min, &max, &mean);
    printf("The minimum is: %d\n", min);
    printf("The maximum is: %d\n", max);
    printf("The mean is: %d\n", mean);
    free(matrix);
    return 0;
}
