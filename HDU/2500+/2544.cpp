#include<stdio.h>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 10000 + 10;

struct edge{
    int u,v,w;  //u:起点,v:终点,w:权值
};

int d[maxn];
edge es[maxn];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) == 2 && n)
    {
        for(int i = 0; i < m; i++)
            scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].w);

        //init
        for(int i = 0; i <= n; i++)
            d[i] = INF;
        d[1] = 0;

        while(true)
        {
            bool update = false;
            for(int i = 0; i < m; i++)
            {
                edge e = es[i];
                if(d[e.u] != INF && d[e.v] > d[e.u] + e.w)
                {
                    d[e.v] = d[e.u] + e.w;
                    update = true;
                }
                if(d[e.v] != INF && d[e.u] > d[e.v] + e.w)
                {
                    d[e.u] = d[e.v] + e.w;
                    update = true;
                }
            }
            if(!update) break;
        }

        printf("%d\n",d[n]);
    }
    return 0;
}
