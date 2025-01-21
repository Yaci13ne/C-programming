#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year;
    printf("give me a year ;");
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        printf("this year %d is a leap year", year);

    else
        printf("this year %d isnt a leap year", year);
}
