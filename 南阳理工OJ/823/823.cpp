#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int INF=1000000;
const int maxn=50+10;
int data[maxn];
int vis[maxn],vis1[maxn],vis2[maxn],N;
int len1,len2;   //�������������еĳ���

//��������г�ʼ��
void init(int *A,int value,int size)
{
    for(int i=0;i<size;i++)
        A[i]=value;
}

//������A�����ݿ���������B��
void copy(int *A,int *B)
{
    int i;
    for(i=0;A[i]!=INF;i++)
        B[i]=A[i];
}

//�õ��������������в����������еĳ���
int getSubSeq(int dir)
{
    int i,j,cnt=-1;
    i=(dir==1?0:N-1);
    init(vis,INF,60);
    for(;i<N && i>=0;i+=dir)
    {
        //Ѱ�Ҹ�Ԫ����vis�е�λ��
        for(j=0;;j++)
            if(data[i]<=vis[j]) break;
        //���Vis�ִ�����ݴ��ڵ�ǰ����,������Ϊ��ǰ����
        if(vis[j]>data[i])
            vis[j]=data[i];
        //���³���
        if(j>cnt) cnt=j;
    }
    //���Ƶ���ص�������ȥ
    if(dir==1) copy(vis,vis1);
    else copy(vis,vis2);
    return cnt+1;
}

//���������������г���
int solve()
{
    int i,j;
    printf("%d %d\n",vis1[len1-1],vis2[len2-1]);
    if(vis1[len1-1]==vis2[len2-1]) return min(len1,len2)*2-1;
    else
    {
        //���±�ֱ�ָ�����������е����һ��Ԫ��
        i=len1-1; j=len2-2;
        while(1)
        {
            if(vis1[i]>vis2[j]) i--;
            else if(vis1[i]<vis2[j]) j--;
            else break;
        }
        return min(i+1,j+1)*2-1;
    }
}

int main()
{
    while(scanf("%d",&N)==1 && N)
    {
        for(int i=0;i<N;i++)
            scanf("%d",&data[i]);
        //�ֱ�õ���������������
        len1=getSubSeq(1);
        len2=getSubSeq(-1);
        printf("%d %d\n",len1,len2);
        printf("%d\n",solve());
    }
    return 0;
}
