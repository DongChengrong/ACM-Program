#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=3000+10;

int G[maxn][maxn];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        int u,v,w;
        memset(G,0,sizeof(0));

        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            if(G[u][v]==0) G[u][v]=w;
            else G[u][v]=min(G[u][v],w);
        }

        long long cost=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                if(G[i][j]!=0) cost+=G[i][j];
        }

        printf("%lld\n",cost);

    }
    return 0;
}
