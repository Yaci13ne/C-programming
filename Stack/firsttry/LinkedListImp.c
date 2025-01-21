#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
  int data;
  struct node *next;

} node;
node *top = 0;

void push(int x)
{

  node *newnode = malloc(sizeof(node));
  newnode->data = x;
  newnode->next = top;

  top = newnode;
}

void pop()
{
  if (top == NULL)
    printf("Underflow\n");

  node *tmp = top;
  top = top->next;
  free(tmp);
}

void display()
{
  node *tmp = top;
  if (tmp == NULL)
  {
    printf("the list is empty");
  }

  while (tmp != NULL)
  {
    printf("%d->", tmp->data);
    tmp = tmp->next;
  }
}

int main()
{

  push(2);
  push(4);
  push(7);

  display();
  printf("NULL");
  printf("\n");
  pop();
  push(19);
  display();
  printf("NULL");
  return 0;
}
