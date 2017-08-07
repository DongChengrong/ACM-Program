#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node,*List;

void init(List &L)
{
    L=(List)malloc(sizeof(Node));
    L=NULL;
}

void insert(List &L,int x)//头插法
{
    List p=(List)malloc(sizeof(Node));
    p->data=x;
    p->next=L;
    L=p;
}

void print(List L)
{
    List p;
    p=L;
    while(L!=NULL)
    {
        printf("%d ",L->data);
        L=L->next;
    }
    printf("\n");
}

void reverse(List &L)
{
    List p,q;
    p=NULL; q=L;
    while(q!=NULL)
    {
        L=L->next;
        q->next=p;
        p=q;
        q=L;
    }
    L=p;
}

int main()
{
    int i,temp;
    List L;
    init(L);
    printf("请输入10个数据：");
    for(i=0;i<10;i++)
    {
        scanf("%d",&temp);
        insert(L,temp);
    }
    print(L);
    reverse(L);
    print(L);
    return 0;
}
