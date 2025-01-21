#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define M 5

int Queue[M];
int front=-1;
int rear=-1;
void enqueue(int x)
{
if(rear == M-1) //Queue FUll
     {printf("Overflow!");
         return;}


else if(front ==-1 && rear ==-1) //Queue empty 
    { front = rear = 0;
              Queue[rear]= x;}

        else { rear++;
                Queue[rear]=x;}

}
 void dequeue(){
  if(front ==-1 && rear ==-1) //Queue is empty
     {  printf("Underflow!");
 return;
 }

  else if(front == rear)//it is last element and when we delete it it becomes empty
  {front = rear = -1;}

else 
front ++;
   

}

void display(){
  if(front ==-1 && rear ==-1) //Queue is empty
       return;
    for(int  i =front ; i< rear+1 ; i++)
    {
printf("Queue[%d]=%d\n",i,Queue[i]);

    }
}


int main(){
enqueue(5);
enqueue(7);
enqueue(9);
enqueue(12);
dequeue();
dequeue();

  enqueue(1);
display();


    return 0;
}