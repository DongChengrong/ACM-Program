#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int INF = 1000000;
const int maxn = 100000+10;
const int maxm = 1000+10;

int n,m;
int a[maxn],b[maxn];
int d[maxm][20];
int k[maxm],p[maxm];

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        int maxp=0,maxa=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            maxa=max(maxa,a[i]);
        }

        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&k[i],&p[i]);
            maxp=max(maxp,p[i]);
        }

        int ok=1;
        long long cost=0;

        if(M[m].p<b[i]) ok = 0;
        if(ok)
        {
            for(int i=1;i<=maxa;i++)
            {

            }
        }


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
