/* Write a C program that recursively swaps the first even number from the left with the first odd number from the right in an array of integers. The program should continue swapping as long as the left index is less than the right index. After each swap, the program should display the array.

The code provided performs the following tasks:

The fct function recursively checks for the first even and odd numbers in the array from the left and right.
Once both numbers are found, they are swapped using the swap function.
The process continues until the left index is greater than or equal to the right index, and then the final array is displayed.*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

fct(int T[], int i, int j, int index1, int index2)
{
    if (j == 0 && i == 6)
        return;

    if (T[j] % 2 != 0)
    {
        return fct(T, i, j - 1, index1, j);
    }

    if (T[i] % 2 == 0)
        return fct(T, i + 1, j, i, index2);

    if (index1 < index2)
        swap(&T[index1], &T[index2]);
}

int main()
{
    int index1 = 0, index2 = 0;
    int T[6] = {1, 7, 10, 12, 3, 66};

    fct(T, 0, 5, index1, index2);

    for (int i = 0; i < 6; i++)
    {
        printf("T[%d]==%d\n", i, T[i]);
    }
    return 0;
}
