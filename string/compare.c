#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[100], d[100];
    printf("Enter the word 1 : ");
    gets(s);
    printf("Enter the word 2 : ");
    gets(d);

    int equal = 1;
    for (int i = 0; s[i] != '\0' || d[i] != '\0'; i++)
    {
        if (s[i] != d[i])
        {
            equal = 0;
            break;
        }
    }

    if (equal)
        printf("they are equal");
    else
        printf("they are not equal");

    return 0;
}