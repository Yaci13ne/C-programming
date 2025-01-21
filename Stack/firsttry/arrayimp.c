#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define M 15
int stack[M];
int top = -1;

bool isEmpty()
{

  return top == -1;
}

void push(int x)
{
  if (top == M - 1)
  {
    printf("Stack Overflow!\n");
    return;
  }
  top++;

  stack[top] = x;
}
void pop()
{
  if (isEmpty())
  {
    printf("Stack Underflow!\n");
    return;
  }

  printf("the item deleted is %d\n", stack[top]);
  top--;
}
int main()
{

  push(1);
  push(3);

  push(7);
  pop();
  push(15); // 15 takes the 7 place
  for (int i = top; i >= 0; i--)
  {
    printf("T[%d]=%d\n", i, stack[i]);
  }
}