#include <stdio.h>
#include <string.h>

char revString(char S[], int size, int i)
{
    return S[size - i - 1]; // Access the reversed index
}

int main()
{
    char S[100];
    printf("Enter the word: ");
    gets(S);

    int size = strlen(S);
    char k[100]; // Array to store the reversed string

    // Populate the reversed string
    for (int i = 0; i < size; i++)
    {
        k[i] = revString(S, size, i);
    }
    k[size] = '\0';

    printf("Reversed word: %s\n", k);

    return 0;
}
