#include <stdio.h>

int reverse_num(int N, int reversed) {
    // Base case: When N becomes 0, return the reversed number
    if (N == 0) {
        return reversed;
    }

    // Recursively call reverse_num, and update the reversed number
    return reverse_num(N / 10, reversed * 10 + N % 10);
}

int main() {
    int number = 12345;
    int reversed = reverse_num(number, 0); // Initial reversed is 0
    printf("Reversed number: %d\n", reversed);
    return 0;
}
