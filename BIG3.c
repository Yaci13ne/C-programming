#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
int value;
struct Node *next;

}Node;
void rec_display(Node* tmp) {
    if (tmp == NULL) return;

    printf("%d -> ", tmp->value);
    rec_display(tmp->next);
}
void rec_displayinv(Node* tmp) {
    if (tmp == NULL) return;
else{
        rec_displayinv(tmp->next);
    printf("%d -> ", tmp->value);}
}
////////////////////////////////////////////////////////////////////////////
int check(Node *head){Node* tmp = head;
    while (tmp != NULL && tmp->next != NULL) {
        if (tmp->value > tmp->next->value)
            return 0;
        tmp = tmp->next;
    }
    return 1;
}
int check_rec(Node *head, Node *tmp) {

    if (tmp == NULL || tmp->next == NULL) {
        return 1;
    }


    if (tmp->value > tmp->next->value) {
        return 0; // Not sorted (decroissant)
    }


    return check_rec(head, tmp->next);
}



Node* inverse_links(Node* head) {
    Node* prev_tmp = NULL;
    Node* tmp = head;
    Node* next = NULL;

    while (tmp != NULL) {
         next = tmp->next;
        tmp->next = prev_tmp;
 prev_tmp = tmp;
       tmp = next;
    }


    head = prev_tmp;
Node* Liste2 = (Node*)malloc(sizeof(Node));
 Liste2=head;

    return Liste2;
}


Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
///////////////////////////////////////////////////////
void insert_sorted(Node **head,int value)
{
    Node* newnode= createNode(value);
   Node *tmp = *head;

  while (tmp->next != NULL && tmp->next->value < value) {
        tmp = tmp->next;
    }
    newnode->next = tmp->next;
    tmp->next = newnode;
}
/////////////////////////(         5           )////////////////////////
Node* fusion(Node *head1, Node *head2) {
    Node* head3 = NULL;
    Node* tmp = head1;

    // all elements from head1 to head3
    while (tmp != NULL) {
        insert_sorted(&head3, tmp->value);
        tmp = tmp->next;
    }

    tmp = head2;
    //  all elements from head2 to head3
    while (tmp != NULL) {
        insert_sorted(&head3, tmp->value);
        tmp = tmp->next;
    }


    return head3;
}




int main()
{
    Node* head = NULL,*tmp;

Node* newnode1 = createNode(1);
Node* newnode2=createNode(2);
Node* newnode3 = createNode(5);
Node* newnode4 =createNode(7);

head = newnode1;
    newnode1->next = newnode2;
    newnode2->next = newnode3;
    newnode3->next = newnode4;
int v;
printf("Enter the value :");
scanf("%d",&v);


insert_sorted(&head,v);




rec_display(head);
printf("NULL");


printf("\n-------------------------------------------------------------\n");
printf("3-1** function to check sorted: (iterative version) :\n");
int c1 = check(head);
if(c1)
  printf("a-the list is sorted in increasing order\n");
   else
     printf("b- the list is not in the increasing order\n");
printf("\n:::::::::::::::::::::::::::\n");


printf("3-2** function to check sorted(recursive version*) : \n");
int c2 = check_rec(head,head);
if(c2)
  printf("a- the list is sorted in increasing order\n");
   else
     printf("b- the list is not in the increasing order\n");

printf("\n-------------------------------------------------------------\n");
printf("****************inverse links *****************\n");
Node* Liste2 = inverse_links(head);
rec_display(Liste2);
printf("NULL");
printf("\n-------------------------------------------------------------\n");


//insertion of second list
Node* head2;
Node* newnode10 = createNode(0);
Node* newnode11=createNode(3);
Node* newnode12 = createNode(8);

head2 = newnode1;
    newnode1->next = newnode2;
    newnode2->next = newnode3;



printf("\n (fusion): \n");
Node* head3 = fusion(head,head2);
rec_displayinv(head3);








    return 0;
}
