#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char S[100];
    printf("Enter the word: ");
    gets(S);
    int alpha = 0, digit = 0, special = 0;
    int i = 0;
    do
    {

        if (S[i] >= '0' && S[i] <= '9')
        {
            printf("%c is a digit\n", S[i]);
            digit++;
        }
        // Check if the character is a letter
        else if ((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z'))
        {
            printf("%c is a letter\n", S[i]);
            alpha++;
        }
        // If it's neither a digit nor a letter
        else
        {
            printf("%c is not a letter or a digit\n", S[i]);
            special++;
        }
        i++;
    } while (S[i] != '\0');

    printf("the number of digits in the string is %d\n", digit);
    printf("the number of alphabet %d", alpha);
    return 0;
}
