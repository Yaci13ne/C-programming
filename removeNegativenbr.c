#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    printf("give numbers of rows: ");
    scanf("%d", &N);
    int cnst = 0;

    float *t = (float *)malloc(N * sizeof(float));
    for (float *p = t; p < t + N; p++)
    {
        printf("element %d: ", (int)(p - t));
        scanf("%f", p);
        if (*p >= 0)
            cnst++;
    }

    float *v = (float *)malloc(cnst * sizeof(float));
    float *t2 = v; // Assign v to t2
    for (float *p = t; p < t + N; p++)
    {
        if (*p >= 0)
            *v++ = *p;
    }

    free(t);
    t = NULL;

    printf("Positive elements:\n");
    for (float *p = t2; p < t2 + cnst; p++)
    {
        printf("%.2f\t", *p);
    }
    printf("\n");

    free(t2);

    return 0;
}
