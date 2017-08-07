#include<stdio.h>
#include<stdlib.h>

const int maxn=1000;

typedef struct Node
{
    int *data;
    int size;
    int top;
}Stack;

void init(Stack &s)
{
    s.data=(int *)malloc(sizeof(int)*maxn);
    s.size=maxn;
    s.top=0;
}

int isFull(Stack s)
{
    return s.top==s.size;
}

int empty(Stack s)
{
    return s.top==0;
}

void push(Stack &s,int e)
{
    if(isFull(s)) return;
    s.data[s.top++]=e;
}

void pop(Stack &s)
{
    if(empty(s)) return;
    s.top--;
}

int top(Stack s)
{
   return s.data[s.top-1];
}

int main()
{
    int e;
    Stack s;
    init(s);
    for(int i=0;i<10;i++)
    {
        scanf("%d",&e);
        push(s,e);
    }
    for(int i=0;i<10;i++)
    {
        printf("%d ",top(s));
        pop(s);
    }
    return 0;
}
