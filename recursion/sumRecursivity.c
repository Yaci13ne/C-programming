#include <stdio.h>
#include <stdlib.h>

int sum(int i , int n ,int sum1)
{ if(i>n) return 0;

return sum1 + sum(i+1,n,sum1);


}




int main()
{ int i=1,n,sum1=0;
printf("enter n: ");
scanf("%d",&n);

int sumit = sum(i,n,sum1);

    printf("The sum of numbers from 1 to 5 : %d",sumit);




}
