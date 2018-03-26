#include<stdio.h>
#include<algorithm>
using namespace std;

struct Node{
    int u,v,w;
};

const int maxn = 100 + 10;
const int maxm = 100000 + 10;

int pa[maxn];
Node G[maxn];

int cmp(Node a, Node b)
{
    return a.w < b.w;
}

void init(int n)
{
    for(int i = 1; i <= n; i++)
        pa[i] = i;
}

int findset(int x)
{
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

int main()
{
    int n,m;
    while(scanf("%d%d",&m,&n) == 2 && m)
    {
        init(n);
        for(int i = 0; i < m; i++)
            scanf("%d%d%d",&G[i].u,&G[i].v,&G[i].w);
        sort(G,G+m,cmp);
        int cnt = n, sum = 0;
        for(int i = 0; i < m; i++)
        {
            if(cnt == 1) break;
            int x = findset(G[i].u);
            int y = findset(G[i].v);
            if(x != y){
                cnt--; pa[x] = y;
                sum += G[i].w;
            }
        }
        if(cnt == 1) printf("%d\n",sum);
        else printf("?\n");
    }
    return 0;
}
