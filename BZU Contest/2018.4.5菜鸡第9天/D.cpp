/*
dijkstra + Â·¾¶»¹Ô­
*/

#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define N 101000
#define INF 0x3f3f3f3f

typedef long long LL;
typedef pair<LL,LL> P;

struct Edge
{
    LL v,w;
    Edge(LL v, LL w)
    {
        this->v = v;
        this->w = w;
    }
};

LL d[N];
vector<Edge> G[N];
LL pre[N],a[N];

int main()
{
    LL n,m;
    while(scanf("%lld%lld",&n,&m) == 2)
    {
        memset(pre,0,sizeof(pre));
        for(int i = 0; i <= n; i++)
            d[i] = -1;

        while(m--)   //create a Graph
        {
            LL u,v,w;
            scanf("%lld%lld%lld",&u,&v,&w);
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
            LL u = p.second;
            if(d[u] < p.first) continue;
            for(LL i = 0; i < G[u].size(); i++)
            {
                Edge e = G[u][i];
                if( d[e.v] > d[u] + e.w || d[e.v] == -1)
                {
                    pre[e.v] = u;
                    d[e.v] = d[u] + e.w;
                    q.push(P(d[e.v],e.v));
                }
            }
        }

        if(d[n] == -1)
        {
            printf("-1\n");
            continue;
        }

        LL id = 0, x = n;
        a[id++] = x;
        while(pre[x] != 0)
        {
            x = pre[x];
            a[id++] = x;
        }

        for(LL i = id - 1; i >= 0; i--)
            printf("%lld ",a[i]);
    }
    return 0;
}
