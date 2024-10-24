#include <stdio.h>
#include<ctype.h>
#include<math.h>
#define MAX 10
int stack[MAX];
int top = -1,i,ele,op1,op2;
char sym;
void push(int);
int pop();
void eval(int,char,int);
int main()
{
    char exp[20];
    printf("Enter the valid postfix expression:\t");
    scanf("%s", exp);
    for (i = 0; exp[i] != '\0'; i++) 
    {
        sym = exp[i];// Check if the symbol is a digit
        if (isdigit(sym)) 
        {
            push(sym - '0');  // Convert char to int
        } 
        else 
        {
            op2 = pop();  // pop the top element as op2
            op1 = pop();  // pop the next element as op1
            eval(op1, sym, op2);  // evaluate the expression
        }
    }
    printf("Result = %d\n", pop());  // Last element is result
}
void push(int ele) 
{
        stack[++top] = ele;  // Increment top before assignment
}
int pop() 
{
        return stack[top--];  // Return the top element and then decrement
}
void eval(int op1, char sym, int op2)
{
    int res;
    switch (sym) 
    {
        case '+':
            res = op1 + op2; //check for addition
            push(res);
            break;
        case '-':
            res = op1 - op2; //check for subraction
            push(res);
            break;
        case '*':
            res = op1 * op2; //check for multiplaction
            push(res);
            break;
        case '/':
            res = op1 / op2; // Check for division
            push(res);
            break;
        case '^':
            res = pow(op1,op2);
            push(res);
            break;
    }
}