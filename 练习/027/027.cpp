#include<stdio.h>
#include<stdlib.h>

#define INF (-100000)
#define MinData 10
typedef int Element;

typedef struct Node
{
    int capacity; //容量
    int size;   //大小
    Element *data;  //数据域
}Node,*Heap;

Heap init(int maxElement);
int isFull(Heap H);
int isEmpty(Heap H);
void insert(Heap &H,Element x);
void print(Heap H);

int isFull(Heap H)
{
    return H->capacity==H->size;
}

int isEmpty(Heap H)
{
    return H->size==0;
}

void insert(Heap &H,Element x)
{
    int i;
    if(isFull(H))
    {
        printf("Heap is full!!!\n");
        return;
    }
    for(i=++H->size;H->data[i/2]>x;i/=2)
        H->data[i]=H->data[i/2];
    H->data[i]=x;
}

Heap init(int maxElement)
{
    Heap H;
    if(maxElement<MinData)
    {
        printf("the init size is too small!!!\n");
        return NULL;
    }
    H=(Heap)malloc(sizeof(Node));
    if(H==NULL)
    {
        printf("out of space!!!\n");
        return NULL;
    }
    H->data=(Element*)malloc((maxElement+1)*sizeof(Node));
    if(H->data==NULL)
    {
        printf("out of space!!!\n");
        return NULL;
    }
    H->capacity=maxElement;
    H->size=0;
    H->data[0]=INF;
    return H;
}

void print(Heap H)
{
    int i;
    for(i=1;i<=H->size;i++)
        printf("%d ",H->data[i]);
    printf("\n");
}

int main()
{
    int i,temp;
    Heap H=init(20);
    printf("请输入10个数据:");
    for(i=0;i<10;i++)
    {
        scanf("%d",&temp);
        insert(H,temp);
    }
    print(H);
    return 0;
}
/*测试数据  32 26 65 24 31 68 19 16 21 13*/
