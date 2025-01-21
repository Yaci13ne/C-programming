#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int sum_fct(int nbr)
{
    if(nbr == 0) return 0;

else
    return nbr%10 + sum_fct(nbr/10);

}

int reverse(int v , int os)
{
    int dup = v;

if (os == 0) return 0;

else
    return ((v%10)*(int)pow(10,os-1)) + reverse(v/10,--os);



}







int main()
{
int value = 160;
int sum = sum_fct(value);
printf("%d\n",sum);



int valuedup = value,cmp=0;
while(valuedup!=0)
{ cmp++;
valuedup/=10;
    }



int result = reverse(value,cmp);


   printf("%d",result);





}
