#include<stdio.h>
#include<stdlib.h>
#include<math.h>

const int maxn=100000;
int n;

typedef struct Node
{
    int front,rear;
    int size;
    long long *data;
}Queue;

void init(Queue &q)
{
    q.size=maxn;
    q.front=q.rear=0;
    q.data=(long long *)malloc(sizeof(long long)*maxn);
}

int empty(Queue q)
{
    if(q.rear-q.front==0) return 1;
    return 0;
}

int isFull(Queue q)
{
    if((q.size+q.rear-q.front)%q.size==q.size-1) return 1;
    return 0;
}

void push(Queue &q,long long e)
{
    if(isFull(q)) return;
    q.data[q.rear%q.size]=e;
    q.rear++,q.rear%=q.size;
}

int front(Queue &q)
{
    if(empty(q)) return 0;
    return q.data[q.front];
}

void pop(Queue &q)
{
    if(empty(q)) return;
    q.front++,q.front%q.size;
}

void bfs()
{
    Queue q;
    init(q);
    push(q,1);
    while(!empty(q))
    {
        long long temp=front(q);
        pop(q);
        for(int i=0;i<2;i++)
        {
            long long x=temp*10+i;
            if(x%n==0) { printf("%lld\n",x); return; }
            push(q,x);
        }
    }
}

int main()
{
    while(scanf("%d",&n)==1 && n)
    {
        if(n==1) printf("1\n");
        bfs();
    }
    return 0;
}
