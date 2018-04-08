
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define N 1010000
#define INF 0x3f3f3f3f

typedef long long LL;

LL a[N];

int main()
{
    int n, k;
    while(scanf("%d%d",&n,&k) == 2)
    {
        for(int i = 0; i < n; i++)
            scanf("%lld",&a[i]);
        sort(a,a+n);
        printf("%lld\n",a[k - 1]);
    }
    return 0;
}