/*
在这个题中，图的权值需要不断的更新，因此采用kruskal算法显然是不合适的
最好的方法是采用prim算法
将所有节点的花费初始化为INF，然后再让任意一个节点花费为0
接下来的工作就是不断的选取和这个树相连的最小权值的节点，把他加到这颗书中
res加上权值
终止条件是没有可以更新的节点时跳出
当然，我们可以通过初始化V = -1来完成这个工作
也可以另设一个update来记录是否有过更新
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define N 110
#define INF 0x3f3f3f3f

int G[N][N];
int cost[N],vis[N];

int main()
{
    int p,r;
    while(scanf("%d",&p) == 1 && p)
    {
        scanf("%d",&r);
        if(p == 1)
        {
            printf("0\n");
            continue;
        }

        memset(G,INF,sizeof(G));  //create Grath
        while(r--)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            G[u][v] = G[v][u] = min(G[u][v],w);
        }

        memset(cost,INF,sizeof(cost));
        memset(vis,0,sizeof(vis));
        int res =  0;
        cost[1] = 0;
        while(1)
        {
            int v = -1;

            for(int i = 1; i <= p; i++)
            {
                if(!vis[i] && (v == -1 || cost[i] < cost[v]))
                    v= i;
            }

            if(v == -1) break;

            vis[v] = 1;
            res += cost[v];

            for(int i = 1; i <= p; i++)    //¸üÐÂ½Úµã
            {
                cost[i] = min(cost[i], G[v][i]);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
