#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // For isalpha() and tolower()

int main()
{
    char S[100];
    printf("Enter the word: ");
    fgets(S, sizeof(S), stdin); // Use fgets instead of gets

    int vowel = 0, cons = 0;
    int i = 0;

    // Convert the string to lowercase and count vowels and consonants
    while (S[i] != '\0' && S[i] != '\n') // Avoid counting the newline character
    {
        char ch = tolower(S[i]);

        if (isalpha(ch)) // Check if the character is a letter
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')
                vowel++;
            else
                cons++;
        }

        i++;
    }

    printf("The number of vowels: %d\n", vowel);
    printf("The number of consonants: %d\n", cons);

    return 0;
}
