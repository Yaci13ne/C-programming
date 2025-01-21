#include <stdio.h>
#include <stdlib.h>

int countit (int nbr , int pow)
{
    if(pow == 0) return 1;

else return nbr * countit (nbr, pow-1);




}




int main()
{
   int Val = 7 , pow = 5;
int result = countit(Val , pow);

printf("%d",result);
}
