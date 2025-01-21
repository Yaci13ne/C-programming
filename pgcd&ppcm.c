#include <stdio.h>
#include <stdlib.h>

// Function to calculate GCD using the Euclidean algorithm
int calculate_gcd(int a, int b)
{
    int rest;
    while (b != 0)
    {
        rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}

// Function to calculate LCM using the GCD
int calculate_lcm(int e1, int e2, int gcd)
{
    return abs(e1 * e2) / gcd; // Formula: LCM(a, b) = |a * b| / GCD(a, b)
}

int main()
{
    int e1, e2, gcd, lcm;

    // Input two numbers
    printf("Enter e1: ");
    scanf("%d", &e1);
    printf("Enter e2: ");
    scanf("%d", &e2);

    // Calculate GCD
    gcd = calculate_gcd(e1, e2);
    printf("The GCD is: %d\n", gcd);

    // Calculate LCM
    lcm = calculate_lcm(e1, e2, gcd);
    printf("The LCM is: %d\n", lcm);

    return 0;
}
