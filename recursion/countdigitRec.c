#include <stdio.h>
#include <stdlib.h>

int ndigit(int nbr, int cmp)
{
    if (nbr == 0)
        return;

    else
    {
        cmp++;
        return ndigit(nbr / 10, cmp);
    }
}

int main()
{
    int n = 14445457, cmp = 0;

    int result = ndigit(n, cmp);
    printf("%d", result);

    return 0;
}
