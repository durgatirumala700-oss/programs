#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct stack
{
    struct node *top;
};
struct node *getnode();
void push(struct stack*,int);
int pop(struct stack*);
int peek(struct stack*);
void display(struct stack*);
int empty(struct stack*);
void push(struct stack *st,int ele)
{
    struct node *newnode;
    newnode=getnode();
    newnode->data=ele;
    if(st->top==NULL)
    {
        st->top=newnode;
    }
    else
    {
        newnode->next=st->top;
        st->top=newnode;
    }
}
struct node *getnode()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=0;
    newnode->next =NULL;
    return newnode;
}
int pop(struct stack *st)
{
    int ele;
    if(st->top==NULL)
    {
        return -1;
    }
    else
    {
        ele=st->top->data;
        st->top=st->top->next;
        return ele;
    }
}
int peek(struct stack *st)
{
    int ele;
    if(st->top==NULL)
    {
        return -1;
    }
    else
    {
        ele=st->top->data;
        return ele;
    }
}
void display(struct stack *st)
{
    struct node *temp;
    temp=st->top;
    if(st->top==NULL)
    {
        printf("list is empty:\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("|%d|",temp->data);
            temp=temp->next;
        }
    }
}
int empty(struct stack *st)
{
    if(st->top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int ch,ele,res;
    struct stack st;
    st. top=NULL;
    while(1)
    {
        printf("\n*********\n\n\t MENU \n*********\n");
        printf("\n1.push\n2.pop\n3.peek\n4.display\n5.empty\n6.exit\n");
        printf("enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter the element:\n");
                          scanf("%d",&ele);
                          push(&st,ele);
                          display(&st);
                          break;
            case 2: res=pop(&st);
                          if(res==-1)
                          {
                              printf("\nstack is empty:");
                          }
                          else
                          {
                              printf("deleted item is %d:\n",res);
                           }
                           display(&st);
                           break;
           case 3: res=peek(&st);
                         if(res==-1)
                         {
                             printf("\n stack is empty:");
                         }
                         else
                         {
                             printf("peeked item is %d:\n",res);
                         }
                         display(&st);
                         break;
            case 4: display(&st);
                          break;
            case 5: res=empty(&st);
                          if(res==1)
                          {
                              printf("\nstack is empty:");
                          }
                          else
                          {
                              printf("\nstack is not empty");
                          }
                          break;
          case 6: exit(0);
                        break;
         default: printf("invalid choice:");
                       break;
        }
    }
    return 0;
}