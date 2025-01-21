#include <stdio.h>
#include <stdlib.h>

int factor (int N)
{ if (N<=1)
 return 1;

 else return N * factor(N-1);

}




int main()
{int nbr;

    printf("enter a number to count its factorial ");
    scanf ("%d",&nbr);

  int n  = factor (nbr);
    printf ("the factorial of %d  = %d" ,nbr,n);
    return 0;
}
