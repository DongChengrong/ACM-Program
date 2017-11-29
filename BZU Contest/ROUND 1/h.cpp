#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 10000 + 10;
int a[maxn];

int main()
{
    int n,q,v;
    int kase = 1;
    while(scanf("%d%d",&n,&q) == 2)
    {
        if(!n && !q) break;
        printf("CASE# %d:\n",kase++);
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        sort(a,a + n);
        while(q--)
        {
            scanf("%d",&v);
            int p = lower_bound(a,a+n,v) - a;
            if(a[p] != v) printf("%d not found\n",v);
            else printf("%d found at %d\n",v,p+1);
        }
    }
    return 0;
}
