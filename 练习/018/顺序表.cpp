#include<stdio.h>
#define OK 1
#define ERROR 0
#define MAX 50
typedef int status;
typedef int element;

typedef struct
{
    element data[50];
    int len;
}SQList;

status init(SQList &L);
status print(SQList L);
status insert(SQList &L,int i,int e);
status getElement(SQList L,int i,element &e);
status locate(SQList L,element e);
status deletee(SQList &L,int i);

status init(SQList &L)
{
    L.len=0;
    return OK;
}

status insert(SQList &L,int i,int e)
{
    int j;
    if(i<1 || i>L.len+1 || L.len==MAX) return ERROR;
    for(j=L.len;j>=i;j--) L.data[j]=L.data[j-1];
    L.data[i-1]=e;
    L.len++;
    return OK;
}

status print(SQList L)
{
    int i;
    if(!L.len) return ERROR;
    for(i=0;i<L.len;i++) printf("%d ",L.data[i]);
    printf("\n");
    return OK;
}

status getElement(SQList L,int i,element &e)
{
    if(i<1 || i>L.len) return ERROR;
    e=L.data[i-1];
    return OK;
}

status locate(SQList L,element e)
{
    int i;
    for(i=0;i<L.len;i++) if(L.data[i]==e) break;
    if(i<0 || i>=L.len) return 0;
    else return i+1;
}

status deletee(SQList &L,int i)
{
    int j;
    if(i<1 || i>L.len) return ERROR;
    for(j=i-1;j<L.len-1;j++) L.data[j]=L.data[j+1];
    L.len--;
    return OK;
}

int main()
{
    int e,i;
    SQList L;
    init(L);
    for(i=0;i<10;i++) insert(L,i+1,i+1);
    print(L);
    insert(L,1,110);
    print(L);
    getElement(L,11,e);
    printf("%d\n",e);
    if(e=locate(L,5)) printf("%d\n",e);
    deletee(L,1);
    print(L);
    return 0;
}
