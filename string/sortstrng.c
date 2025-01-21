#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // For isalpha() and tolower()

int main()
{
    char S[100];
    printf("Enter the word: ");
    fgets(S, sizeof(S), stdin); // Use fgets instead of gets

    int T[256] = {0};
    for (int i = 0; S[i] != '\0'; i++)
    {
        T[S[i]]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if (T[i] != 0)
        {
            for (int k = 0; k < T[i]; k++)
            // Print the character
            {
                printf("\n%c is repeated %d\n", i, T[i]);
                break;
            }
        }
    }
    return 0;
}
