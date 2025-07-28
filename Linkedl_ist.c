// This file contain both singly and doubly linked list (scroll down for the double) 
// The functions impelemented are insert(by position) , delete(by value) , sort(ascending order) , reverse
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data ;
    struct node*next;
}node;

node *head =NULL;
int nodes_count =0;
void  traversal();
void insert();
void delete_node();
void sort();

int main(){
    int choose;
    do {
    printf("~~~Welcome to linked list manager~~~");
    printf("\n1.traversal");
    printf("\n2.insert");
    printf("\n3.delete");
    printf("\n4.Sort");
    printf("\n5.Reverse");
    printf("\n5.Exit");
    printf("\nEnter choice:");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        traversal();
        break;
    case 2:
        insert();
        break;
    case 3:
        delete_node();
        break;

    case 4:
        sort();
        break;
    case 5:
        reverse();
        break;
    case 6:
        printf("\nExiting...");
        break;
    default:
    printf("\nInvalid choice..");
        break;
    }

    }while(choose !=6);
}

void  traversal(){
    if(head==NULL){
        printf("\nThe linked list is empty");
        return;
    }
   node* temp = head;
    printf("Linked List Contents:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}
void insert(){
     int newData, choose, position;
     printf("\nEnter the new node value:");
     scanf("%d", &newData);
     printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
     printf("\n1.insertion in specific position?");
     printf("\n2.insertion in end of list?");
     printf("\nchoice:");
     scanf("%d",&choose);
     node *newNode = (node*)malloc(sizeof(node));
     newNode->data = newData;
     //for insertion in end
     if(choose==2){
        newNode->next = NULL;
        // no nodes yet
        if(head == NULL){
            head = newNode;    
        }

        else{
            node*temp = head;
        while(temp->next != NULL){
            temp = temp->next;
            }
        temp->next = newNode;
            }
        }
    // insert at position
    else if(choose == 1)
    {

        printf("\nEnter position:");
        scanf("%d", &position);
        if(nodes_count <=position){
            printf("\nInvalid position!!");
            return;
        }
        // at first node
        if (position == 0) {
        newNode->next = head;
        head = newNode;
        } 
        // other nodes
        else {
        node *temp = head;
        node *prev = NULL;
        for (int i = 0; i < position; i++) {
            prev = temp;
            temp = temp->next;
        }
        newNode->next = temp;
        prev->next = newNode;
}
    }
    nodes_count++;
    printf("Node inserted.\n");

}
void delete_node() {
    // no nodes yet
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    int val;
    printf("Enter value to delete: ");
    scanf("%d", &val);

    node* temp = head;
    node* prev = NULL;

    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }
    // vlaue in frist node
    if (prev == NULL) {
        head = head->next;
    }
    // skipping the middle node to delete it 
     else {
        prev->next = temp->next;
    }

    free(temp);
    nodes_count--;
    printf("Node with value %d deleted.\n", val);
}
// sortinf usig bubble sort
void sort() {
    if (head == NULL || head->next == NULL) {
        printf("List is too short to sort.\n");
        return;
    }

    int swapped;
    node *ptr1;
    node *ptr2 = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != ptr2) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);

    printf("Linked list sorted in ascending order.\n");
}
void reverse(){
    if(nodes_count < 2){
        printf("\nnot enough nodes");
        return;
    }
    node *prev = NULL;
    node *current = head;
    node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("Linked list has been reversed.\n");
}
////////////////////////////////////////////////////////////////
