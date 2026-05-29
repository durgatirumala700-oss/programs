#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coef,exp;
    struct node *next;
};
struct node *getnode();
struct node *createpoly();
void display(struct node*);
struct node *insert(struct node*,int,int);
struct node *add(struct node*,struct node*);
struct node *getnode()
{
    struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coef=0;
    newnode->exp=0;
    newnode->next=NULL;
    return newnode;
}
struct node *createpoly()
{
    int i,n,coef,exp;
    struct node *phead=NULL;
    printf("enter the number of terms:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the term %d of coef and exp:",i+1);        scanf("%d%d",&coef,&exp);
        phead=insert(phead,coef,exp);
    }
    return phead;
}
struct node *insert(struct node *phead,int coef,int exp)
{
    struct node *newnode,*temp;
    newnode=getnode();
    newnode->coef=coef;
    newnode->exp=exp;
    if(phead==NULL || exp>phead->exp)
    {
        newnode->next=phead;
        phead=newnode;
    }
    else
    {
        temp=phead;
    while(temp->next!=NULL&& exp<temp->next->exp)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return phead;
}
void display(struct node *phead)
{
    struct node *temp;
    temp=phead;
    while(temp!=NULL)
    {
        printf("%dX^%d+",temp->coef,temp->exp);
        temp=temp->next;
    }
}
struct node *add(struct node *ph1,struct node *ph2)
{
    struct node *ph3=NULL;
    while(ph1!=NULL && ph2!=NULL)
    {
        if(ph1->exp>ph2->exp)
        {
            ph3=insert(ph3,ph1->coef,ph1->exp);
            ph1=ph1->next;
        }
        else if(ph1->exp<ph2->exp)
        {
            ph3=insert(ph3,ph2->coef,ph2->exp);
            ph2=ph2->next;
        }
        else
        {
            ph3=insert(ph3,ph1->coef+ph2->coef,ph1->exp);
            ph1=ph1->next;
            ph2=ph2->next;
        }
    }
    while(ph1!=NULL)
    {
        ph3=insert(ph3,ph1->coef,ph1->exp);
            ph1=ph1->next;
    }
    while(ph2!=NULL)
    {
        ph3=insert(ph3,ph2->coef,ph2->exp);
            ph2=ph2->next;
    }
    return ph3;
}
int main()
{
    struct node *ph1=NULL,*ph2=NULL,*ph3=NULL;
    printf("create first polynomial is:\n");
    ph1=createpoly();
    printf("create second polynomial is:\n");
    ph2=createpoly();
    printf("\n first polynomial is:\n");
    display(ph1);
    printf("\n second polynomial is:\n");
    display(ph2);
    ph3=add(ph1,ph2);
    printf("\n resultant polynomial is:\n");
    ph3=add(ph1,ph2);
    display(ph3);
}