/*Question:
Write a C program that swaps the first even number from the left with the first odd number from the right in an array of integers. The program should repeat this process until the indices of the even and odd numbers cross each other. After each swap, the array should be printed.

The program should:

Identify the first even number from the left.
Identify the first odd number from the right.
Swap these numbers.
Repeat the process until the two indices cross.
Print the array after each swap.*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int index1 = 0, index2 = 0;
    int T[6] = {1, 7, 10, 12, 66, 40};

    while (index1 < index2)
    {
        // Find the first even number's index from the left
        for (int i = 0; i < 6; i++)
        {
            if (T[i] % 2 == 0)
            {
                index1 = i;
                break;
            }
        }

        // Find the first odd number's index from the right
        for (int j = 5; j >= 0; j--)
        {
            if (T[j] % 2 != 0)
            {
                index2 = j;
                break;
            }
        }

        // Swap if index1 is less than index2
        if (index1 < index2)
        {
            swap(&T[index1], &T[index2]);
        }

        // Print the modified array after each swap
        for (int i = 0; i < 6; i++)
        {
            printf("T[%d] == %d\n", i, T[i]);
        }
    }

    return 0;
}
