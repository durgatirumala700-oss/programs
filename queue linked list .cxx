#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct queue
{
    struct node *front,*rear;
};
struct node *getnode();
void insert(struct queue*,int);
int deletion(struct queue*);
void display(struct queue*);
int empty(struct queue*);
void insert(struct queue*qu,int ele)
{
    struct node *newnode;
    newnode=getnode();
    newnode->data=ele;
    if(qu->front==NULL && qu->rear==NULL)
    {
        qu->rear=newnode;
        qu->front=newnode;
    }
    else
    {
        qu->rear->next=newnode;
        qu->rear=newnode;
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
int deletion(struct queue *qu)
{
    int ele;
    if(empty(qu))
    {
        return -1;
    }
    else
    {
        ele=qu->front->data;
        qu->front=qu->front->next;
        return ele;
    }
}
void display(struct queue *qu)
{
    struct node *temp;
    temp=qu->front;
    if(qu->front==NULL)
    {
        printf("queue is empty:\n");
    }
    else
    {
        printf("\n elements are:\n");
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
    }
}
int empty(struct queue *qu)
{
    if(qu->front==NULL)
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
    struct queue q;
    q. rear=NULL;
    q. front=NULL;
    while(1)
    {
        printf("\n*********\n\n\t MENU \n*********\n");
        printf("\n1.insert\n2.delete\n3.display\n4.empty\n5.exit\n");
        printf("enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter the element:\n");
                          scanf("%d",&ele);
                          insert(&q,ele);
                          display(&q);
                          break;
            case 2: res=deletion(&q);
                          if(res==-1)
                          {
                              printf("\nqueue is empty:");
                          }
                          else
                          {
                              printf("deleted item is %d:\n",res);
                           }
                           display(&q);
                           break;
            case 3: display(&q);
                          break;
            case 4: res=empty(&q);
                          if(res==1)
                          {
                              printf("\nqueue is empty:");
                          }
                          else
                          {
                              printf("\nqueue is not empty");
                          }
                          break;
          case 5: exit(0);
                        break;
         default: printf("invalid choice:");
                       break;
        }
    }
    return 0;
}