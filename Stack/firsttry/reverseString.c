#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define M 15
char Stack[15],top=-1;

void push(char x){
   if(top==M-1)
   {printf("Overflow");
   exit(1);

  
} top++;
   Stack[top]=x;

}


void pop(){
 if(top==-1)
   {printf("Underflow");
   exit(1);
   }


   top--;


}

int main(){

printf("Enter a word :");
char hi[100];
gets(hi);

int size = strlen(hi);
printf("the size is %d\n",size);


for(int i =0 ; i< size ; i++)
{
push(hi[i]);
}
printf("the reversed word is : ");
for(int i = top ; i>= 0 ; i--)
{printf("%c",Stack[i]);

}





}