#include<stdio.h>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
#define N 105

int pa[N];
struct Edge
{
    int a,b,w;
}G[N * N];

void init(int n)
{
    for(int i = 1; i <= n; i++)
        pa[i] = i;
}

int cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int findset(int x)
{
    return x == pa[x] ? x : pa[x] = findset(pa[x]);
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) == 2 && n)
    {
        for(int i = 0; i < m; i++)
            scanf("%d%d%d",&G[i].a,&G[i].b,&G[i].w);
        sort(G,G+m,cmp);
        int i = 0;
        int l = 0;
        int ans = INF;
        while(l < m)
        {
            init(n);
            int cnt = n;
            for(i = l; i < m; i++)
            {
                if(cnt == 1) break;
                int a = G[i].a; int b = G[i].b;
                a = findset(a); b = findset(b);
                if(a != b)
                {
                    pa[a] = pa[b];
                    cnt--;
                }
            }
            if(cnt == 1) ans = min(ans,G[i - 1].w - G[l].w);
            else break;
            l++;
        }
        if(ans == INF) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
