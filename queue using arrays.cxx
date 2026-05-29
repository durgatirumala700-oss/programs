#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
struct queue
{
    int rear,front;
    int items[SIZE];
};
void insert(struct queue*,int);
int deletion(struct queue*);
int peek(struct queue*);
int empty(struct queue*);
void display(struct queue*);
void insert(struct queue *qu,int ele)
{
    if(qu->rear==SIZE-1)
    {
        printf("queue is overflow:");
    }
    else
    {
        qu->rear=qu->rear+1;
        qu->items[qu->rear]=ele;
    }
}
int deletion(struct queue *qu)
{
    int ele;
    if(qu->front>qu->rear)
    {
        printf("queue is underflow:");
        return -1;
    }
    else
    {
        ele=qu->items[qu->front];
        qu->front=qu->front+1;
    return ele;
    }
}
int peek(struct queue *qu)
{
    int ele;
    if(qu->front > qu->rear)
    {
        printf("queue is underflow:");
        return -1;
    }
    else
    {
        ele=qu->items[qu->front];
        return ele;
    }
}
void display(struct queue *qu)
{
    int i;
    for(i=qu->front;i<=qu->rear;i++)
    {
        printf("\n %d indexed element is|%d|",i,qu->items[i]);
    }
}
int empty(struct queue *qu)
{
    if(qu->front > qu->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int  main()
{
    struct queue q;
    q. rear=-1;
    q. front=0;
    int ch,ele;
    while(1)
    {
    printf("\n1.insert:\n2.delete:\n3.peek:\n4.display:\n5.empty:\n6.exit:\n");
    printf("enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("enter the element to insert:\n");
                     scanf("%d",&ele);
                     insert(&q,ele);
                     break;
       case 2: ele=deletion(&q);
                      if(ele==-1)
                    {
                     printf("queue is empty:");
                    }
                      else
                 {
                   printf("removed element is %d:",ele);
                  }
                     break;
       case 3: ele=peek(&q);
                    if(ele==-1)
                   {
                     printf("queue is empty:");
                   }
                  else 
                  {
                    printf("top element is %d:",ele);
                  }
                    break;
       case 4: display(&q);
                     break;
        case 5: ele=empty(&q);
                    if(ele==1)
                  {
                     printf("queue is empty:");
                  }
                 else
               {
                printf("queue contain elements:");
               }
               break;
        case 6: exit(0);
                      break;
        default: 
                       printf("invalid choice:");
                       break;
    }
    }
}