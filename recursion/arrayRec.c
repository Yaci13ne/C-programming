#include <stdio.h>
#include <stdlib.h>

void arrayit(int T[] , int size , int i)
{ if(i >= size)
return;

    else {

printf("T[%d]==%d\n",i,T[i]);
arrayit(T,size,i+1);

}
}//never use (return) keyword before printing (case of you need to display 8.6.9.12.10.7.5.0.





int if_sorted(int T[],int N,int i)
    {
        if(i==N) return 1;
        if(T[i+1]<T[i]) return 0;
        else
            if_sorted(T,N,i+1);


    }





int main()
{int N=8;
    int T[8]={0,1,2,3,7,9,10,12};


   arrayit(T,N,0);

          int n=  if_sorted(T,N,0);
            if(n)
                printf("the array is sorted");
            else
                printf("it is not");


    return 0;
}
