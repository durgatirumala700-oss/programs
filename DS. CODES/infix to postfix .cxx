#include<stdio.h>
#define MAX 20
struct stack
{
    int top;
    char items[MAX];
};
struct stack s;
void push(struct stack*,char);
char pop(struct stack*);
void intopost(char []);
char peek(struct stack*);
int isoper(char);
int isp(char);
int icp(char);
int isempty(struct stack*);
int main()
{
    char infix[MAX];
    s. top=-1;
    printf(" Enter infix expression:");
    scanf("%s",infix);
    printf("\n The original infix expression is:%s",infix);
   intopost(infix);
   return 0;
}
void intopost(char infix[MAX])
{
    char postfix[MAX];
    char sym,topsym;
    int i,j=0;
    for(i=0;(sym=infix[i])!='\0';i++)
    {
        if(isoper(sym))
        {
            postfix[j]=sym;
            j++;
        }
        else if(sym=='(')
        {
            push(&s,sym);
        }
        else if(sym==')')
        {
            topsym=pop(&s);
            while(!isempty(&s)&& topsym!='(')
            {
               postfix[j]=topsym;
               j++;
               topsym=pop(&s);
            }
        }
        else
        {
            while(!isempty(&s) && icp(sym)<=isp(peek(&s)))
            {
                topsym=pop(&s);
                postfix[j]=topsym;
                j++;
            }
            push(&s,sym);
        }
    }
    while(!isempty(&s))
    {
        topsym=pop(&s);
        postfix[j]=topsym;
        j++;
    }
    postfix[j]='\0';
    printf("\n postfix expression is:%s",postfix);
}
int isoper(char c)
{
    if((c>='0'&&c<='9') || (c>='a'&&c<='z') || (c>='A'&&c<='Z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *st,char sym)
{
    if(st->top==MAX-1)
    {
        printf("stack is overflow:");
    }
    else
    {
        st->top=st->top+1;
        st->items[st->top]=sym;
    }
}
char pop(struct stack *st)
{
    char sym;
    if(st->top==-1)
    {
        return -1;
    }
    else
    {
        sym=st->items[st->top];
        st->top=st->top-1;
        return sym;
    }
}
char peek(struct stack *st)
{
    char sym;
    if(st->top==-1)
    {
        return -1;
    }
    else
    {
        sym=st->items[st->top];
        return sym;
    }
}
int isempty(struct stack *st)
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
int isp(char c)
{
    switch(c)
    {
        case '(' : return 0;
        case '+' :
        case '-' : return 1;
        case '*' :
        case '/' : return 2;
        case '^': return 3;
    }
}
int icp(char c)
{
    switch(c)
    {
        case '+' :
        case '-' : return 1;
        case '*' :
        case '/' : return 2;
        case '^': return 3;
    }
}