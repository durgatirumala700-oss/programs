#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 20
struct stack
{
    int top;
    double items[MAX];
};
struct stack s;
double oper(char,double,double);
void push(struct stack*,double);
double pop(struct stack*);
int empty(struct stack*);
double eval(char []);
int isdigit(char);
int main()
{
    char expr[MAX];
    s. top=-1;
    printf("Enter the postfix expression:\n");
    scanf("%s",&expr);
    printf("\n The original postfix expression is %s:",expr);
    printf("\nResult\n%1f",eval(expr));
    return 0;
}
double eval(char expr[])
{
    int i;
    char c;
    double opnd1,opnd2,value;
    for(i=0;(c=expr[i])!='\0';i++)
    {
        if(isdigit(c))
        {
            push(&s,(double)(c-'0'));
        }
        else
        {
            opnd2=pop(&s);
            opnd1=pop(&s);
            value=oper(c,opnd1,opnd2);
            push(&s,value);
        }
    }
    return (pop(&s));
}
int isdigit(char symb)
{
    if(symb>='0' && symb<='9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
double oper(char symb,double op1,double op2)
{
    switch(symb)
    {
        case  '+' :
                      return (op1+op2);
                      break;
        case '-' :
                     return (op1-op2);
                     break;
        case  '*' :
                     return (op1*op2);
                     break;
        case  '/' :
                      if(op2==0)
                      {
                          printf("Error:division by zero!\n");
                          return -1;
                      }
                      return op1/op2;
                      break;
       case '^' :
                    return(pow(op1,op2));
                    break;
       default: printf("\nillegal operation");
                      break;
                      exit(0);
    }
}
void push(struct stack *st,double a)
{
    if(st->top==MAX-1)
    {
        printf("\n stack is overflow:");
    }
    else
    {
        st->top=st->top+1;
        st->items[st->top]=a;
    }
}
double pop(struct stack *st)
{
    double a;
    if(st->top==-1)
    {
        return -1;
    }
    else
    {
        a=st->items[st->top];
        st->top--;
    }
    return a;
}
int empty(struct stack *st)
{
    if(st->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}