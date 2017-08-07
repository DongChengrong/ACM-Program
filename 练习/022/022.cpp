#include<stdio.h>
#include<stdlib.h>

#define Element int

typedef struct Node{
    Element data;
    struct Node *left,*right;
}Node,*SearchTree;

void init(SearchTree &T)
{
    T=NULL;
}

SearchTree makeEmpty(SearchTree &T)
{
    if(T)
    {
        makeEmpty(T->left);
        makeEmpty(T->right);
        free(T);
    }
    return NULL;
}

SearchTree insert(SearchTree &T,Element e)
{
    if(T)
    {
        if(e>T->data) T->right=insert(T->right,e);
        else if(e<T->data) T->left=insert(T->left,e);
    }
    else
    {
        T=(SearchTree)malloc(sizeof(Node));
        T->left=NULL;
        T->right=NULL;
        T->data=e;
    }
    return T;
}

void print(SearchTree T)   //采用先序遍历打印出的数据会从大到小排序
{
    if(T)
    {
        print(T->left);
        printf("%d ",T->data);
        print(T->right);
    }
}

Element findMin(SearchTree T)
{
    if(T)
    {
        if(T->left) return findMin(T->left);
        else return T->data;
    }
    return -1;
}

Element findMax(SearchTree T)
{
    if(T)
    {
        if(T->right) return findMax(T->right);
        else return T->data;
    }
    return -1;
}

SearchTree deleteMin(SearchTree &T)
{
    if(T)
    {
       if(T->left) T->left=deleteMin(T->left);
       else
       {
           if(T->right) return T->right;
           else
           {
               free(T);
               return NULL;
           }
       }
    }
    return NULL;
}

SearchTree mydelete(SearchTree &T,Element e)
{
    if(T)
    {
        if(e>T->data) T->right=mydelete(T->right,e);
        else if(e<T->data) T->left=mydelete(T->left,e);
        else
        {
            if(T->left && T->right)
            {
                T->data=findMin(T->right);
                deleteMin(T->right);
                return T;
            }
            else if(T->left && !T->right)
            {
                return T->left;
            }
            else if(T->right && !T->left)
            {
                return T->right;
            }
            else return NULL;
        }
        return T;
    }
    return NULL;
}

int main()
{
    int i=10,data;
    SearchTree T;
    init(T);
    while(i--)
    {
        scanf("%d",&data);
        insert(T,data);
    }
    print(T); printf("\n");
    printf("max:%d\nmin:%d\n",findMax(T),findMin(T));
    printf("删除最小元素后:"); deleteMin(T); print(T); printf("\n");
    printf("请输入你想要删除的元素:\n"); scanf("%d",&data); mydelete(T,data); print(T); printf("\n");
}
//测试数据
//12 20 35 68 94 100 2 57 71 36
