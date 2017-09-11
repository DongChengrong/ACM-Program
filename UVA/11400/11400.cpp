#include<stdio.h>
#include<algorithm>
using namespace std;

const int INF = 10000000;
const int maxn = 1000 + 10;

struct Node
{
    int v,k,c,l;

    bool operator<(const Node &u)const
    {
        return v < u.v;
    }

}a[maxn];

int cost[maxn],num[maxn];

int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n )
    {
        for(int i = 1; i <= n; i++)
            scanf("%d %d %d %d",&a[i].v,&a[i].k,&a[i].c,&a[i].l);

        sort(a + 1, a + 1 + n);

        num[0] = 0;
        for(int i = 1; i <= n; i++)
            num[i] = num[i - 1] + a[i].l;

        cost[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            cost[i] = INF;
            for(int j = 0;j < i; j++)
                cost[i] = min( cost[i], cost[j] + (num[i] - num[j])*a[i].c + a[i].k );
        }

        printf("%d\n",cost[n]);
    }
    return 0;
}
