#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1000+10;
int m,n;
int topo[maxn],G[maxn][maxn],vis[maxn],cur;

//���г�ʼ��
void init()
{
    cur=n;
    memset(G,0,sizeof(G));
    memset(vis,0,sizeof(vis));
}

//ʵ��������Ӧ�÷�����ȷ��񣬵����������������ȷ��
//��������㷨�������ڱ���
void dfs(int u)
{
    for(int v=0;v<n;v++)
    {
        if(G[u][v] && !vis[v])
            dfs(v);
    }
    vis[u]=1;
    topo[--cur]=u;
}

//������������
int toposort()
{
    for(int i=0;i<n;i++)
        if(!vis[i]) dfs(i);
    return 1;
}

int main()
{
    while(scanf("%d%d",&n,&m)==2 && n)
    {
        init();
        //��������ͼ
        for(int i=0;i<m;i++)
        {
            int v,u;
            scanf("%d%d",&u,&v);
            G[u-1][v-1]=1;
        }
        //��Ϊû�и����޷���������ʱ��������������Ӧ���������ݶ��Ϸ�
        toposort();
        for(int i=0;i<n-1;i++)
            printf("%d ",topo[i]+1);
        printf("%d\n",topo[n-1]+1);
    }
    return 0;
}
