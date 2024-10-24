#include <stdio.h>
#include <stdlib.h>
#define MAX_size 5
int stack[MAX_size];
int ele, top = -1;
void push(int); // declaration
int pop();
void status();
void display();
int main() 
{
    int ch;
    while (1) 
    {
        printf("Menu \n 1.push \n 2.pop \n 3.status \n 4.display \n 5.exit \n enter your choice: ");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1:
                printf("enter element to push: ");
                scanf("%d", &ele);
                push(ele); // push ele to the function of push
                break;
            case 2:
                ele = pop(); 
                printf("popped element: %d\n", ele);
                break;
            case 3:
                status();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}
void push(int ele) // declaring function
{ 
    if (top == MAX_size - 1)// to check if the stack is full
    { 
        printf("Stack is full\n");
    } 
    else 
    {
        stack[++top] = ele; // increment before storing
    }
}
int pop() 
{
    if (top == -1) 
    {
        printf("Stack is empty\n");
    } 
    else 
    {
        return stack[top--]; // return and then decrement top
    }
}
void status()
{
    if (top == -1) 
    {
        printf("Stack is empty\n");
    } 
    else if (top == MAX_size - 1) 
    {
        printf("Stack is full\n");
    } 
    else 
    {
        display();
    }
}
void display()
{
    int i;
    printf("Stack elements are:\n");
    for (i = top; i >= 0; i--)// start from top down to 0
    { 
        printf("%d\n", stack[i]);
    }
}