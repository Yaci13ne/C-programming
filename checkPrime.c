#include <stdio.h>
#include <math.h>

int main()
{
    int isprime = 1;
    int N = 13;

    if (N < 2)
        isprime = 0; // Numbers less than 2 are not prime
    else {
        for (int i = 2; i <= sqrt(N); i++) {
            if (N % i == 0) {
                isprime = 0;
                break;
            }
        }
    }

    if (isprime)
        printf("It is prime\n");
    else
        printf("The number isn't prime\n");

    return 0;
}
