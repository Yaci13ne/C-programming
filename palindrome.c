#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 int main() {int i;
    char chr[20],second[20],third[20];
    printf("give a word :");
    gets (chr);

    int t = strlen(chr);

for (i = t -1 ; i >= 0 ; i--)
third [t - i - 1] = chr [i];


if (strcmp(third , chr)== 0)
{
    puts("the word is palindrome ");
}
else
    puts ("the word is not palindrome");


return 0;
 }
