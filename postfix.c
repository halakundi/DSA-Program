#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define Max 10
int stack[Max],top=-1;
void push(int);
int pop();
void eval(int op1,char sym,int op2);
int main()
{
    int i=0,op1,op2;
    char exp[20];
    char sym;
    printf("enter the postfix expression:\t");
    scanf("%s",exp);
    for(i=0;exp[i]!='\0';i++)
    {
        sym=exp[i];
        if(isdigit(sym))
        {
            push(sym-'0');
        }
        else
        {
            op1=pop();
            op2=pop();
            eval(op1,sym,op2);
        }
    }
    printf("result=%d",pop());
    return 0;        
}
void push(int ele)
{
    stack[++top]=ele;
}
int pop()
{
    return stack[top--];
}
void eval(int op1,char sym,int op2) 
{
    int res;
    switch(sym)
    {
        case '+':
        res=op1+op2;
        push(res);
        break;
        case '-':
        res=op1-op2;
        push(res);
        break;
        case '*':
        res=op1*op2;
        push(res);
        break;
        case '/':
        res=op1/op2;
        push(res);
        break;
        case '^':
        res=pow(op1,op2);
        push(res);
        break;    
    }
}