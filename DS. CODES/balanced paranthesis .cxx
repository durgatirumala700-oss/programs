#include<stdio.h>
#include<string.h>
#define MAX 20
char stack[MAX];
int top=-1;
void push(char);
void push(char ch)
{
    top=top+1;
    stack[top]=ch;
}
char pop();
char pop()
{
    return stack[top--];
}
int checkbalanced(char[]);
int checkbalanced(char expr[])
{
    int i;
    char ch;
    for(i=0; expr[i]!='\0'; i++)
    {
        ch=expr[i];
        if(ch=='(' || ch=='{' || ch=='[')
        {
            push(ch);
        }
        else if(ch==')' || ch=='}' || ch==']')
        {
            if(top==-1)
            {
                return 0;
            }
            char temp=pop();
            if((ch==')' && temp!='(') ||
           (ch=='}' && temp!='{') ||
           (ch==']' && temp!='[') )
           {
               return 0;
           }
        }
    }
    if(top==-1)
    {
        return 1;
    }else
    {
        return 0;
    }
}
int main()
{
    char expr[20];
    printf("Enter the expression:");
    scanf("%s",&expr);
    if(checkbalanced(expr))
    {
        printf("Balanced Paranthesis:");
    }
    else
    {
        printf("Un balanced paranthesis:");
    }
    return 0;
}