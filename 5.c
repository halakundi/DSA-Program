#include<stdio.h>
#include<ctype.h>
char stack[20];
int top=-1;
void push(char ele);
char pop();
int priority(char sym);
int main()
{
    int i=0;
    char exp[20];
    char sym,ele;
    printf("enter valid infix expression:");
    scanf("%s",exp);
    printf("\n postfix:");
    for(i=0;exp[i]!='\0';i++) //read each char from infix
    {
        sym=exp[i];
        if(isalnum(sym)) //check is alpha numic
        printf("%c ",sym); //print output if it is operand alphabent
        else if(sym=='(')
        push(sym); //push symbol if it iparenthsis
        else if(sym==')') //if reparenthsis encountered
        {
            while((ele=pop())!='(') //pop all the elements from stack till
            printf("%c ",ele); //if parenthsis encountered and print on output
        }
        else
        {
            // check priority of incoming symbol
            while(priority(stack[top])>=priority(sym))
            printf("%c ",pop()); //and stack[top]symbol print on output
            push(sym); //push the symbol
        }
    }
    while(top!=-1) //pop remaining all the ele from stack and print on output
    {
        printf("%c ",pop());
    }
    return 0;
}
void push(char ele)
{
    stack[++top]=ele;
}
char pop()
{
    return stack[top--];
}
int priority(char sym) //initialize priority
{
    if(sym=='(')
    return 0;
    if(sym=='+'||sym=='-')
    return 1;
    if(sym=='*'||sym=='/'||sym=='%')
    return 2;
    if(sym=='^')
    return 3;
    return 0;
}