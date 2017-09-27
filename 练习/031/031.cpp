#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

typedef Node *List;

void init(List &L)
{
    L = (List)malloc(sizeof(Node));
    L->value = 1;
}

int main()
{
    List L;
    init(L);
    printf("%d\n",L->value);
    return 0;
}
