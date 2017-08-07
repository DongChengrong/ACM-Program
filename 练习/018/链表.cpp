#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef int Status;
#define OK 1
#define ERROR 0

typedef struct LinkNode
{
    element data;
    struct LinkNode *next;
}LinkNode,*LinkedList;

Status init(LinkedList &list)      //��ʼ����ͷ���ĵ�����
{
    list=(LinkedList)malloc(sizeof(LinkNode));
    if(list==NULL) return ERROR;
    list->next=NULL;
    return OK;
}

Status add(LinkedList &list,element e)
{
    LinkedList p,q;
    if(list==NULL) return ERROR;
    p=list;
    // while(p->next!=NULL) p=p->next;
    q=(LinkedList)malloc(sizeof(LinkNode));
    if(q==NULL) return ERROR;
    q->data=e;
    q->next=p->next;
    p->next=q;
    return OK;int i=1;
}

int locate(LinkedList list,element e)
{
    int i=1;
    LinkedList p;
    if(list==NULL) return ERROR;
    p=list->next;
    while(p->data!=e && p->next!=NULL) { p=p->next; i++; }
    if(p->next==NULL) return ERROR;
    return i;
}

LinkedList findPreElement(LinkedList list,element e)
{
    LinkedList p;
    if(list==NULL) return NULL;
    p=list;
    while(p->next!=NULL && p->next->data!=e) p=p->next;
    if(p->next==NULL) return NULL;
    return p;
}

Status deleteElement(LinkedList &list,element e)
{
    int i=1;
    LinkedList p,q;
    if(list==NULL) return ERROR;
    p=list->next;
    p=findPreElement(list,e);
    if(p==NULL) return ERROR;
    q=p->next;
    p->next=q->next;
    free(q);
    return OK;
}

element getElement(LinkedList list,int locate)
{
    int i=1;
    LinkedList p;
    if(list==NULL) return ERROR;
    p=list->next;
    while(p!=NULL && i!=locate) { p=p->next; i++; }
    if(p==NULL) return ERROR;
    return p->data;
}

Status insert(LinkedList &list,element e,int locate)
{
    int i=1;
    LinkedList p,q;
    if(list==NULL) return ERROR;
    p=list;
    while(p!=NULL && i!=locate) { p=p->next; i++; }
    if(p!=NULL)
    {
        q=(LinkedList)malloc(sizeof(LinkNode));
        q->data=e;
        q->next=p->next;
        p->next=q;
    }
    else return ERROR;
    return OK;
}

void print(LinkedList list)
{
    LinkedList p;
    if(list==NULL) return;
    p=list->next;
    while(p!=NULL) { printf("%d ",p->data); p=p->next; }
    printf("\n");
}

int main()
{
    int i,e;
    LinkedList list;
    if(init(list)==ERROR) { printf("��ʼ������!!!\n"); return 0; }
    for(i=1;i<=10;i++) add(list,i);
    printf("ԭʼ����"); print(list);
    printf("��ѡ��Ҫȡ��Ԫ�ص�λ��"); scanf("%d",&i); printf("%d\n",getElement(list,i));
    printf("��ѡ��Ҫ��λ��Ԫ��:"); scanf("%d",&i); i=locate(list,i); if(i==ERROR) printf("���޴�Ԫ��\n"); else printf("%d\n",i);
    printf("��ѡ������������ĸ�Ԫ��:"); scanf("%d%d",&i,&e); insert(list,e,i);
    printf("��������������"); print(list);
    printf("��ѡ��Ҫɾ����Ԫ��"); scanf("%d",&e); i=deleteElement(list,e);
    if(i==ERROR) printf("ɾ��ʧ��!!!\n");
    else { printf("ɾ������������£�"); print(list); }
    return 0;
}
