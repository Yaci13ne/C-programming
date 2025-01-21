#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[100];
    printf("Enter the sentence : ");
    gets(s);
    int nbr = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {

        if (s[i] != ' ' && s[i + 1] == ' ' || s[i] != ' ' && s[i + 1] == '\0')
        {

            nbr++;
        }
    }

    printf("nbr ; %d ", nbr);

    return 0;
}