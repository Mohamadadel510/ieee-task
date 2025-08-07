// basic stack module using arrays
#include <stdio.h>
#define MAX 100

int stack[MAX];
int top =-1;

void display();
void peek();
void pop();
void push();

int main()
{
    display();
    return 0;
}

void display(){
    printf("/******************\\\n");
    printf("WElCOME TO MYSTACK WIZERD ;)\n");
    printf("1- PUSH\n");
    printf("2- POP\n");
    printf("3- PEEK\n");
    printf("4-EXIT <)\n");
    printf("/******************\\\n");

    int choose ;
    do{
        printf("Enter your choice:");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            printf("THE WIZERD WILL MISS YOU \n");
            break;
        default:
            printf("NOT A VALID CHOICE !!!\n");
            break;
        }
    }while (choose != 4);

}
void peek(){
    if(top ==-1)
    {
        printf("Stack is Empty!!\n");
        return;
    }
    printf("The value: %d\n", stack[top]);
}
void push(){
    if(top > MAX){
        printf("STACK OVERFLOW!!\n");
        return;
    }
    int value ;
    printf("Enter a value:");
    scanf("%d",&value);
    top++;
    stack[top] = value;
    printf("Value Pushed!!\n"); 
}
void pop(){
    if (top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }
    top--;
    printf("Value POPPED\n");
    
}
