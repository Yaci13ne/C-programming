#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* a = b x + rest

   13 = 2 * 6 + 1
   2 = 1 * 2 + 0
** 1 = 0 * 0 + 1
additional ** in the recursion

*/

int rec_gcd(int a, int b)
{
    if (b == 0)
        return a;

    return rec_gcd(b, a % b);
}

int main()
{
    int a = 48, b = 36;
    int mult = a * b;
    int rest = 0;
    do
    {
        rest = a % b;
        a = b;
        b = rest;

    } while (rest != 0);

    printf("the gcd of a and b is %d \n", a);

    int gcd = rec_gcd(a, b);
    printf("the gcd recursion %d \n ", gcd);

    int lcm = mult / gcd;
    printf("the lcm of a and b is %d \n", lcm);

    return 0;
}

/*LCM(a,b)=   ∣a×b∣   / GCD(a,b).

*/