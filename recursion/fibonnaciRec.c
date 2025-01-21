#include <stdio.h>
#include <stdlib.h>

void fibon(int i, int U1, int U2)
{
    if (i >= 10)
        return;
    int fib = U1 + U2;
    printf("%d\t", fib);

    return fibon(i + 1, U2, fib);
}

int main()
{
    int U1 = 0;
    int U2 = 1;
    int i = 1;
    fibon(i, U1, U2);
}
