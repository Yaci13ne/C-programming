#include <stdio.h>
#include <math.h>

int tobinary(int nbr, int n, int i)
{
    if (nbr == 0)
    {
        return n * pow(10, i);
    }

    printf("2 * %d + %d\n", nbr, n);

    return tobinary(nbr / 2, nbr % 2, i + 1) + n * pow(10, i);
}

int main()
{
    int nbr = 25;
    int n = tobinary(nbr / 2, nbr % 2, 0);

    printf("%d\n", n);

    return 0;
}
