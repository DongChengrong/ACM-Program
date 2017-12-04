#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;
const int INF = 0x3f3f3f3f;
int n;
int m[maxn][maxn];

void Floyd()
{
    memset(m,INF,sizeof(m));
    for(int i = 1; i <= n; i++)
    {
        int t,u,s;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d%d",&u,&s);
            m[i][u] = s;
        }
    }

    for(int t = 1; t <= n; t++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                m[i][j] = min(m[i][j], m[i][t] + m[t][j]);
}

int main()
{
    while(scanf("%d",&n) == 1 && n)
    {
        Floyd();
        int Min = INF,time;
        for(int i = 1; i <= n; i++)
        {
            int tmp = 0;
            for(int j = 1; j <= n; j++)
            {
                if(i == j) continue;
                tmp = max(tmp,m[i][j]);
            }
            if(Min > tmp)
            {
                Min = tmp;
                time = i;
            }
        }
        if(Min >= INF) printf("disjoint\n");
        else printf("%d %d\n",time,Min);
    }
    return 0;
}
