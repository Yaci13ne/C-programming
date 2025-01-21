#include <stdio.h>
#include <stdlib.h>

int N = 5, M = 4;

// Recursive function to check if there are common elements
int fct_rec(int T1[], int T2[], int i, int j) {
    if (i == N) return 1;  // Reached the end of T1
    if (j == M) return fct_rec(T1, T2, i + 1, 0);  // Move to the next element of T1
    if (T1[i] == T2[j]) return 0;  // Found a common element, return 0
    return fct_rec(T1, T2, i, j + 1);  // Continue comparing in T2
}

int main() {
    int T1[] = {1, 4, 6, 8, 10};
    int T2[] = {2, 5, 9, 15};

    // Call the recursive function
    int check = fct_rec(T1, T2, 0, 0);

    if (check) {
        printf("No same elements in both arrays\n");
    } else {
        printf("There exist the same elements in both arrays\n");
    }

    return 0;
}
