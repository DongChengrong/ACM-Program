#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int INF = 1000000;
const int maxn = 100000+10;
const int maxm = 1000+10;

int n,m;
int a[maxn],b[maxn];
int d[maxm];

struct Node
{
    int k,p;
}M[maxm];

int cmp(struct Node m1,struct Node m2)
{
    return m1.p<m2.p;
}

int dp(int i)
{
    memset(d,INF,sizeof(d));
    if(M[m].p<b[i]) return -1;

    d[a[i]] = 0;


    return d[0];
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i],&b[i]);

        for(int i=1;i<=m;i++)
            scanf("%d%d",&M[i].k,&M[i].p);

        int ok=1;
        long long cost=0;

        sort(M,M+m,cmp);

        for(int i=1;i<=n;i++)
        {
            int ans=dp(i);
            if(ans<0) ok=0;
            else cost+=ans;
        }

        if(ok) printf("%lld\n",cost);
        else printf("-1\n");

    }
    return 0;
}
