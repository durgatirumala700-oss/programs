#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int stack[SIZE];
int top=-1;
void push(int);
int pop();
int peek();
void display();
void push(int ele)
{
    if(top==SIZE-1)
    {
        printf("stack is overflow:");
    }
    else
    {
        top=top+1;
        stack[top]=ele;
    }
}
int pop()
{
    int ele;
    if(top==-1)
    {
        printf("stack is underflow:");
    }
    else
    {
        ele=stack[top];
        top=top-1;
    }
    return ele;
}
int peek()
{
    int ele;
    if(top==-1)
    {
        printf("stack is underflow:");
    }
    else
    {
        ele=stack[top];
    }
    return ele;
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("stack is underflow:");
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("%d\t",stack[i]);
        }
    }
}
int main()
{
    while(1)
    {
    int ch,ele;
    printf("\n1.PUSH:\n2.POP:\n3.PEEK:\n4.DISPLAY:\n5.EXIT:\n");
    printf("enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("PUSH\n");
                     printf("enter the item to push:\n");
                     scanf("%d",&ele);
                     push(ele);
                     break;
       case 2: ele=pop();
                     printf("popped element is %d:",ele);
                     break;
       case 3: ele=peek();
                    printf("peeked element is %d:",ele);
                    break;
       case 4: display();
                     break;
       case 5: exit(0);
                     break;
        default: printf("invalid choice:");
                       break;
    }
    }
}