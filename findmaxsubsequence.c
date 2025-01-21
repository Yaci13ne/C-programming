#include <stdio.h>
#include <stdlib.h>
typedef struct node{
 int value;
 struct node* prev;
 struct node* next;
}node;

node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void display(node* head)
{node *tmp = head;
    while (tmp !=0)
 { printf("%d\t",tmp->value);
 tmp = tmp->next;
    }
}

//

//*/
int findMaxSubsequence(node* head, node** start, node** end) {
    int max2 = 0;           
    int max = 0;        

    *start = head; 
    *end = head;
    for (node* tmp = head; tmp != NULL; tmp = tmp->next) {
        max = 0;
        for (node* tmp2 = tmp; tmp2 != NULL; tmp2 = tmp2->next) {
            max += tmp2->value; 

            if (max >= max2) { 
                max2 = max;
                *start = tmp;  
                *end = tmp2;  
            }
        }
    }

    printf("The maximal sum is: %d\n", max2);
    return max2; // Optionally return the maximal sum
}

    
 

void findsub(node* head ,node* tail)
{
     node* newnode =NULL;
     node* start = head;
     node* end = head;
     findMaxSubsequence(head,&start,&end);
  
 
  
  if (start != NULL && end != NULL) {
        end->next = NULL; // Terminate the subsequence
        display(start);   // Display the subsequence
    } else {
        printf("Error: Unable to find a valid subsequence.\n");
    }

}



int main()
{
node * head;
node * tail;
head =NULL;

node* newnode1 = createNode(1);

node* newnode2=createNode(-2);
node* newnode3 = createNode(3);
node* newnode4 =createNode(10);
node* newnode5 =createNode(-4);
node* newnode6 =createNode(7);
node* newnode7 =createNode(2);
node* newnode8 =createNode(-5);

head =tail= newnode1;

    newnode1->next = newnode2;
    newnode1->prev=NULL;
    newnode2->next = newnode3;
    newnode2->prev=newnode1;
    newnode3->next = newnode4;
    newnode3->prev=newnode2;
     newnode4->next = newnode5;
     newnode4->prev=newnode3;
      newnode5->next = newnode6;
      newnode5->prev=newnode4;
       newnode6->next = newnode7;
       newnode6->prev = newnode5;
        newnode7->next = newnode8;
        newnode7->prev = newnode6;
        newnode8->next=NULL;
        newnode8->prev = newnode7;

        tail = newnode8;


findsub(head ,tail);
return 0;

}