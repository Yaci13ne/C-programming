#include <stdio.h>
#include <stdlib.h>



void read_rec(int T[] , int size ,  int i)
{
    if(i==size) return ;
         printf("T[%d]==",i);
            scanf("%d",&T[i]);
                return read_rec(T,size,i+1);
    }

void display_rec (int T[] , int size , int i)
{
    if (i==size) return ;
        printf("T[%d]==%d\n",i,T[i]);
                 return display_rec(T,size,i+1);
    }



void displayinv_rec (int T[] , int size , int i)
{
    if (i<0) return ;
         printf("T[%d]==%d\n",i,T[i]);
             return displayinv_rec(T,size,i-1);
}


int Sum_rec (int T[],int size ,int i,int sumit)
{
    if(i==size) return sumit;
         sumit+=T[i];
                return Sum_rec(T,size,i+1,sumit);
}

int occ_rec(int T[],int i,int size,int V)
{if(i==size) return 0;
    if(T[i]==V) return 1 + occ_rec(T,i+1,size,V);
      if(T[i]!=V) return occ_rec(T,i+1,size,V);
}



int rech_dec(int T[],int v,int start,int end)
{
    int mid = (start+end)/2;
   if (end<start) return -1;
    if(T[mid]==v) return mid;
        if(T[mid]>v) return rech_dec(T,v,start,mid-1);
        if(T[mid]<v) return rech_dec(T,v,mid+1,end);


}


int main()
{ int N;
printf("how many elements :");
scanf("%d",&N);
int T[N];
read_rec(T,N,0);
puts();
display_rec(T,N,0);
puts();
displayinv_rec(T,N,N-1);
puts();

int sum = Sum_rec(T,N,0,0);
printf("The sum is %d\n",sum);



int V = 3;
int rep = occ_rec(T,0,N,V);

printf("number of rep of this V is %d\n",rep);



int TD[5] ={1,2,3,8,9};
int search =rech_dec(TD,V,0,4);
if(search!=-1)
    printf("the value %d exist at index %d",V,search);

    else printf("the value doesnt exist in the array");






    return 0;
}
