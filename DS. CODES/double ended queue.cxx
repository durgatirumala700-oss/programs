#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct deque
{
    int items[MAX];
    int front,rear;
};
void insert_front(struct deque*,int);
void insert_rear(struct deque*,int);
int deletion_front(struct deque*);
int deletion_rear(struct deque*);
int empty(struct deque*);
int peek_front(struct deque*);
int peek_rear(struct deque*);
void display(struct deque*);
void insert_front(struct deque *dqu,int ele)
{
    if((dqu->front==0 && dqu->rear==MAX-1) ||
    (dqu->front==dqu->rear+1))
    {
        printf("\n circular queue if full:");
        return;
    }
    else if(dqu->front==-1)
    {
        dqu->rear=0;
        dqu->front=0;
    }
    else
    {
        if(dqu->front==0)
        {
            dqu->front=MAX-1;
        }
        else
        {
            dqu->front=dqu->front-1;
        }
    }
    dqu->items[dqu->front]=ele;
}
void insert_rear(struct deque *dqu,int ele)
{
    if((dqu->front==0 && dqu->rear==MAX-1) ||
    (dqu->front==dqu->rear+1))
    {
        printf("\n circular queue if full:");
        return;
    }
    else if(dqu->front==-1)
    {
        dqu->rear=0;
        dqu->front=0;
    }
    else
    {
        if(dqu->rear==MAX-1)
        {
            dqu->rear=0;
        }
        else
        {
            dqu->rear=dqu->rear+1;
        }
    }
    dqu->items[dqu->rear]=ele;
}
int deletion_front(struct deque *dqu)
{
    int ele;
    if(dqu->front==-1)
    {
        return -1;
    }
    ele=dqu->items[dqu->front];
    if(dqu->front==dqu->rear)
    {
        dqu->front=-1;
        dqu->rear=-1;
    }
    else
    {
            if(dqu->front==MAX-1)
            {
                dqu->front=0;
            }
            else
            {
                dqu->front++;
            }
        }
        return ele;
}
int deletion_rear(struct deque *dqu)
{
    int ele;
    if(dqu->front==-1)
    {
        return -1;
    }
    ele=dqu->items[dqu->rear];
    if(dqu->front==dqu->rear)
    {
        dqu->front=-1;
        dqu->rear=-1;
    }
    else
    {
            if(dqu->rear==0)
            {
                dqu->rear=MAX-1;
            }
            else
            {
                dqu->rear--;
            }
        }
        return ele;
}
void display(struct deque *cqu)
{
    int i;
    if(cqu->front==-1)
    {
        printf(" circular queue is empty:\n");
    }
    else
    {
        if(cqu->front<=cqu->rear)
        {
            for(i=cqu->front; i<=cqu->rear; i++)
            {
                printf("\n %d indexed element is |%d|",i,cqu->items[i]);
            }
        }
        else
        {
            for(i=cqu->front;i<=MAX-1;i++)
            {
                printf("\n %d indexed element is |%d|",i,cqu->items[i]);
            }
            for(i=0;i<=cqu->rear;i++)
            {
                printf("\n %d indexed element is |%d|",i,cqu->items[i]);
            }
        }
    }
}
int empty(struct deque *dqu)
{
    if(dqu->front==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int peek_front(struct deque *dqu)
{
    if(dqu->front==-1)
    {
        return -1;
    }
    else
    {
        return dqu->items[dqu->front];
    }
}
int peek_rear(struct deque *dqu)
{
    if(dqu->front==-1)
    {
        return -1;
    }
    else
    {
        return dqu->items[dqu->rear];
    }
}
int main()
{
    int ch,ele;
    struct deque dqu;
    dqu. rear=-1;
    dqu. front=-1;
    while(1)
    {
        printf("\n*********\n\n\t MENU \n*********\n");
        printf("\n1.insert at front:\n2.insert at rear:\n3.delete at front\n4.delete at rear:\n5.peek at front:\n6.peek at rear:\n7.empty:\n8.display:\n9.exit:\n");
        printf("enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nenter the element:\n");
                          scanf("%d",&ele);
                          insert_front(&dqu,ele);
                          printf("\n elelments are:");
                          display(&dqu);
                          break;
            case 2: printf("\nenter the element:\n");
                          scanf("%d",&ele);
                          insert_rear(&dqu,ele);
                          printf("\n elelments are:");
                          display(&dqu);
                          break;
            case 3: ele=deletion_front(&dqu);
                          if(ele==-1)
                          {
                           printf("\nqueue is empty:");
                          }
                          else
                          {
                           printf("deleted element is %d:",ele);
                          printf("\n elelments are:");
                          display(&dqu);
                           break;
           case 4: ele=deletion_rear(&dqu);
                          if(ele==-1)
                          {
                           printf("\nqueue is empty:");
                          }
                          else
                          {
                           printf("deleted element is %d:",ele);
                          printf("\n elelments are:");
                          display(&dqu);
                          break;
            case 5: ele=peek_front(&dqu);
                          if(ele==-1)
                          {
                            printf("\n circular queue is empty:");
                          }
                              else
                              {
                                  printf("\n first element in circular queue is %d:",ele);
                              }
                                  break;
             case 6: ele=peek_rear(&dqu);
                          if(ele==-1)
                          {
                              printf("\n circular queue is empty:");
                          }
                              else
                              {
                                  printf("\n first element in circular queue is %d:",ele);
                              }
                                  break;
            case 7: ele=empty(&dqu);
                         if(ele==1)
                         {
                             printf("\n queue is empty:");
                         }
                         else
                         {
                           printf("\n queue is not empty:");
                         }
                         break;
             case 8: printf("\n elements are:");
                           display(&dqu);
                          break;
          case 9: exit(0);
                        break;
         default: printf("invalid choice:");
                       break;
                          }
                          }
        }
    }
}