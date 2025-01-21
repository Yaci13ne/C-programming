#include <stdio.h>
#include <stdlib.h>

typedef struct node{
 int data;
 struct node *left,*right;
}node;

node* create(int x)
{ node * newnode = (node*)malloc(sizeof(node));
 newnode->data =x;
if(x == -1 ) return NULL;

printf("Enter left child of this node %d ",x);
  newnode->left =create(x);


printf("Enter right child of this node %d ",x);
  newnode->right =create(x);

return newnode; 
}


int main(){
 node * root = NULL;
 root = create(5);
  



}