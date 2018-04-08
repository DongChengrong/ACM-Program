/*
dijkstra算法的变种算法
制定两个点，求出最短路径
可以找到最短路径的值，但是记录路径是一个关键的问题
利用pre记录上一个节点
*/

#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define N 101000
#define INF 0x3f3f3f3f

typedef pair<int,int> P;

struct Edge
{
    int v,w;
    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

int d[N];
vector<Edge> G[N];
int pre[N],a[N];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        memset(d,INF,sizeof(d));
        memset(pre,0,sizeof(pre));

        while(m--)   //create a Graph
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back(Edge(v, w));
            G[v].push_back(Edge(u, w));
        }

        priority_queue<P, vector<P>, greater<P> > q;
        d[1] = 0;
        q.push(P(0,1));

        while(!q.empty())
        {
            P p = q.top();
            q.pop();
            int v = p.second;
            if(d[v] < p.first) continue;
            for(int i = 0; i < G[v].size(); i++)
            {
                Edge e = G[v][i];
                if( d[e.v] > d[v] + e.w)
                {
                    pre[e.v] = v;
                    d[e.v] = d[v] + e.w;
                    q.push(P(d[e.v],e.v));
                }
            }
        }

        if(d[n] == INF)
        {
            printf("-1\n");
            continue;
        }

        int id = 0, x = n;
        a[id++] = x;
        while(pre[x] != 0)
        {
            x = pre[x];
            a[id++] = x;
        }

        for(int i = id - 1; i >= 0; i--)
            printf("%d%c",a[i],i == 0 ? '\n' : ' ');
    }
    return 0;
}
