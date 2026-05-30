#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct queue
{
    int items[MAX];
    int front,rear;
};
void enqueue(struct queue*,int);
void dequeue(struct queue*);
void display(struct queue*);
void enqueue(struct queue*qu,int ele)
{
    if((qu->front==0 && qu->rear==MAX-1) ||
    (qu->front==qu->rear+1))
    {
        printf("queue if full:");
        return;
    }
    if(qu->front==-1)
    {
        qu->rear=0;
        qu->front=0;
    }
    else
    {
        if(qu->rear==MAX-1)
        {
            qu->rear=0;
        }
        else
        {
            qu->rear=qu->rear+1;
        }
    }
    qu->items[qu->rear]=ele;
}
void dequeue(struct queue *qu)
{
    int ele;
    if(qu->front==-1)
    {
        printf("queue is underflow:");
        return;
    }
    else
    {
        ele=qu->items[qu->front];
        printf("element removed is %d",ele);
        if(qu->front==qu->rear)
        {
        qu->front=-1;
        qu->rear=-1;
        }
        else
        {
            if(qu->front==MAX-1)
            {
                return qu->front==0;
            }
            else
            {
                qu->front++;
            }
        }
        printf("element removed is %d",ele);
    }
}
void display(struct queue *qu)
{
    int i;
    if(qu->front==-1)
    {
        printf(" circular queue is empty:\n");
    }
    else
    {
        if(qu->front<=qu->rear)
        {
            for(i=qu->front; i<=qu->rear; i++)
            {
                printf("\n %d indexed element is |%d|",i,qu->items[i]);
            }
        }
        else
        {
            if(i=qu->front;i<=MAX-;i++)
            {
                printf("\n %d indexed element is |%d|",i,qu->items[i]);
            }
        }
    }
}
int main()
{
    int ch,ele;
    struct queue qu;
    qu. rear=-1;
    qu. front=-1;
    while(1)
    {
        printf("\n*********\n\n\t MENU \n*********\n");
        printf("\n1.insert\n2.delete\n3.display:\n4.exit\n");
        printf("enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter the element:\n");
                          scanf("%d",&ele);
                          enqueue(&qu,ele);
                          break;
            case 2: dequeue(&q);
                           break;
            case 3: display(&qu);
                          break;
          case 4: exit(0);
                        break;
         default: printf("invalid choice:");
                       break;
        }
    }
    return 0;
}