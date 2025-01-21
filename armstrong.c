#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int count_digits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}


int armstrong_rec(int n, int digits) {
    if (n == 0) return 0;


    return pow(n % 10, digits) + armstrong_rec(n / 10, digits);
}

int main() {
    int n = 1634;


    int digits = count_digits(n);
    int result = armstrong_rec(n, digits);
    if (result == n)
        printf("This number is an Armstrong number: %d = %d\n", result, n);
    else
        printf("It is not an Armstrong number\n");

    return 0;
}
