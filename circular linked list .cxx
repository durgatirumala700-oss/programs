#include<stdio.h>
#include<stdlib.h>
struct node
{
       int data;
      struct node *next;
};
struct node *getnode();
struct node *createlist();
void display(struct node*);
struct node *insert( struct node*);
struct node *deleteNode( struct node*);
struct node *getnode()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=0;
    newnode->next=NULL;
    return newnode;
}
struct node *createlist()
{
    struct node *head,*first,*newnode;
    first=getnode();
    head=first;
    newnode=getnode();
    printf("enter the value of  the create list:");
    scanf("%d",&newnode->data);
    while(newnode->data!=-22)
    {
        first->next=newnode;
        first=newnode;
        newnode=getnode();
        printf("enter the value of the create list:");
        scanf("%d",&newnode->data);
        newnode->next=head->next;
    }
    return head->next;
}
void display(struct node *head)
{
    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {
           while(temp->next!=head)
          {
               printf("%d->",temp->data);
               temp=temp->next;
           }
             printf("%d->",temp->data);
    }
}
struct node *insert(struct node* head)
{
    struct node *newnode,*temp;
    temp=head;
    int ch,pos,i;
    if(head!=NULL)
    {
        newnode=getnode();
        printf("enter the value to be inserted:");
        scanf("%d",&newnode->data);
        printf("\n1.insert at beg:\n2.insert at        end:\n3.insert at specific position:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: while(temp->next!=head)
                          {
                              temp=temp->next;
                          }
                        newnode->next=head;
                        temp->next=newnode;
                          head=newnode;
                          break;
            case 2:while(temp->next!=head)
                         {
                              temp=temp->next;
                         }
                         newnode->next=head;
                          temp->next=newnode;
                           break;
            case 3: printf("enter the position to be inserted:");
                          scanf("%d",&pos);
                          if(pos==1)
                          {
                              while(temp->next!=head)
                              {
                                  temp=temp->next;
                              }
                              newnode->next=head;
                              temp->next=newnode;
                              head=newnode;
                          }
                          else
                          {
                              for(i=0;i<pos-1;i++)
                              {
                                  temp=temp->next;
                              }
                              newnode->next=temp->next;
                              temp->next=newnode;
                          }
                          break;
             default:
                              printf("invalid choice:");
                              break;
        }
        return head;
    }
}
struct node *deleteNode(struct node* head)
{
    struct node *temp,*secondtemp;
    int ch,pos,i;
    temp=head;
    if(head==NULL)
    {
        printf("No element to be deleted:");
    }
    else
    {
        printf("\n1.delete at beg:\n2.delete at end:\n3.delete at specified position:");
        printf("enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(temp->next==head)
            {
                head=NULL;
            }
            else
            {
                secondtemp=head->next;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=head->next;
                head->next=NULL;
                head=secondtemp;
            }
            break;
            case 2:if(temp->next==head)
                         {
                             head=NULL;
                         }
                         else
                         {
                             while(temp->next->next!=head)
                           {
                               temp=temp->next;
                           }
                           temp->next=head;
                         }
                           break;
            case 3: printf("enter the position to be deleted:");
            scanf("%d",&pos);
            if(pos==1)
            {
                if(temp->next==head)
                         {
                             head=NULL;
                         }
                         else
                         {
                             while(temp->next!=head)
                             {
                                 temp=temp->next;
                             }
                             secondtemp=head->next;
                             temp->next=secondtemp;
                             head->next=NULL;
                             return secondtemp;
                         }
            }
            else
            {
                for(i=0;i<pos-1;i++)
                {
                    temp=temp->next;
                }
                temp->next=temp->next->next;
            }
            break;
            default:
                          printf("invalid choice:");
                          break;
        }
        return head;
    }
}
int main ()
{
    struct node *start;
    int ch;
    while(1)
    {
        printf("\n***********\n MENU \n********\n");
        printf("\n1.createlist:\n2.insert:\n3.deleteNode:\n4.display:\n5.exit:");
        printf("\nenter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: start=createlist();
                          display(start);
                          break;
            case 2: start=insert(start);
                          display(start);
                          break;
            case 3: start=deleteNode(start);
                          display(start);
                           break;
            case 4: display(start);
                          break;
            case 5: exit(0);
                          break;
            default: 
                             printf("invalid choice:");
                             break;
        }
    }
}