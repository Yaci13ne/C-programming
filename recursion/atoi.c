#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
   int x = 256;
   char str[100];
  sprintf(str, "%d", x);
  strrev(str);
 int rev = atoi(str);
 printf("%d :: %d",x,rev);
}
