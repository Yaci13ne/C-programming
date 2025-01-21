#include <stdio.h>
#include <string.h>

// Function to reverse a string in place
void revString(char S[], int start, int end)
{
    if (start >= end)
        return;

    // Swap characters
    char temp = S[start];
    S[start] = S[end];
    S[end] = temp;

    // Recursive call
    revString(S, start + 1, end - 1);
}

int main()
{
    char S[100];
    printf("Enter the word: ");
    fgets(S, sizeof(S), stdin);

    // Remove the newline character from fgets
    S[strcspn(S, "\n")] = '\0';

    int size = strlen(S);
    printf("%d", size);
    // Reverse the string
    revString(S, 0, size - 1);

    // Print the reversed string
    printf("Reversed word: %s\n", S);

    return 0;
}
