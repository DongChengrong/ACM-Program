
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
using namespace std;

#define N 1010000
#define INF 0x3f3f3f3f

typedef long long LL;

LL a[N];

int main()
{
    int n, k;
    while(scanf("%d",&n) == 1)
    {
        for(int i = 0; i < n; i++)
            scanf("%lld",&a[i]);

        sort(a,a+n);

        int i = 0,j = n - 1;
        int cnt = 0;
        for(int i = 0; i < n - 1; i++)
            for(int j = i + 1; j < n; j++)
            {
                int mid = -1 * (a[i] + a[j]);
                int p = lower_bound(a,a+n,mid) - a;
                if(a[p] == mid && p > j)
                {
                    cnt++;
                    printf("%lld %lld %lld\n",a[i],a[j],a[p]);
                }
            }
        if(!cnt) printf("No Solution\n");
    }
    return 0;
}