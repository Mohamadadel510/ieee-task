// This file contain both singly and doubly linked list (scroll down for the double) 
// The functions impelemented are insert(by position) , delete(by value) , sort(ascending order) , reverse
// sorry if the code a little bit chaotic 🙏 
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
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data ;
    struct node*prev;
    struct node*next;
}node;
// intializing a head node
node *head =NULL;
// count the nodes
int nodes_count =0;

// functions prototype
void  traversal();
void insert();
void delete_node();
void reverse();
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
    int i ;
    while (i < nodes_count) {
        printf("%d)%d -> ",i, temp->data);
        temp = temp->next;
        i++;
    }
    printf("NULL\n");
    printf("NO.Nodes: %d\n", nodes_count);

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
            newNode->prev =temp;  
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
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
        } 
        // other nodes
        else {
        node *temp1 = head;
        node *temp2 = NULL;
        for (int i = 0; i < position; i++) {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = newNode;
        temp2->prev = newNode;
        newNode->next = temp2;
        newNode->prev = temp1;
}
    }
    nodes_count++;
    printf("Node inserted.\n");

}
void delete_node() {
    // no nodes yet
    if (head == NULL || nodes_count ==0) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    int val;
    printf("Enter value to delete: ");
    scanf("%d", &val);

    node* temp = head;
    node *temp2 = NULL;
    

    while (temp != NULL && temp->data != val) {
        temp = temp->next;
        temp2 = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }
    // deleting the head node
    if (temp == head) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    }
    // deleting at the middle or end

    else{
        temp->prev->next = temp->next;
        if(temp->next !=NULL){
            temp->next->prev = temp->prev;
        }
    }
    free(temp);
    nodes_count--;
    printf("Node with value %d deleted.\n", val);
}
// sortinf usig bubble sort
void sort() {
    // 1 node or less
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
    // list less than two nodes so we cant reverse
    if(nodes_count < 2){
        printf("\nnot enough nodes");
        return;
    }
    // intializing the nodes using to reverse
    node *temp1 = head;
    node *temp2 = temp1->next;

    temp1->next = NULL;
    temp1->prev = temp2;
    while (temp2 != NULL)
    {
        temp2->prev = temp2->next;
        temp2->next = temp1;
        temp1 = temp2 ;
        temp2 = temp2->prev;



    }
    head = temp1;
    printf("Linked list has been reversed.\n");
}
