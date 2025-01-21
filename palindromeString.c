#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int ispali (char S[])
{ char rev[100];
strcpy(rev,S);

strrev(rev);

if(strcmp(rev,S)==0) return 1;
 else return 0;




}



int main()
{
    char Str[100];
    gets(Str);
int n = ispali(Str);
if(n==1)
    printf ("the word is palindrome ");

else printf("it is not palindrome");

return 0;
}
