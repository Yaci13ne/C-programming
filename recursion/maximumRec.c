#include <stdio.h>
#include <stdlib.h>

int maximum(int T[] ,int size, int max ,int i)
{
    if (i==size) return max;

    else if(T[i]>max)
        return maximum(T,size,T[i],i+1);

    else return maximum(T,size,max,i+1);
    }






int main()
{
   int N=8;
    int T[8]={1,5,77,10,12,9,6,118};

int big = maximum(T,N,T[0],0);


printf("%d",big);
    return 0;
}
