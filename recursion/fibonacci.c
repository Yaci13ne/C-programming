#include <stdio.h>

int fibbint(int k)
{
    if (k < 2)
        return 1;

    return fibbint(k - 1) + fibbint(k - 2);
}

int main()
{
    int k;
    printf("Enter k for fibonacci serie : ");
    scanf("%d", &k);
    for (int i = 0; i <= k; i++)

        printf("%d\t", fibbint(i));
}