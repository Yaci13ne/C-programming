
#include <stdio.h>
#include <stdlib.h>

void replace(int size, float *v)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += v[i];
    }
    float S = sum / size;
    printf("the average is %f :\n", S);
    int count = 0;
    float *T = (float *)malloc(size * sizeof(float)); // Allocate memory for T

    for (int i = 0; i < size; i++)
    {
        if (v[i] < S)
        {
            T[count] = v[i]; // Store the value in T
            count++;
        }
    }
    printf("number that are less then average :\n");
    for (int i = 0; i < count; i++)
    {
        printf("%f\n", T[i]); // Print the values in T
    }
    free(T); // Free allocated memory
}

int main()
{
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);
    float *p = (float *)malloc(N * sizeof(float)); // Allocate memory for p

    for (int i = 0; i < N; i++)
    {
        printf("T[%d] = ", i);
        scanf("%f", &p[i]); // Read values into p
    }
    replace(N, p); // Call the replace function
    free(p);       // Free allocated memory
    return 0;
}
