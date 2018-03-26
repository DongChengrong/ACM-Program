#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long long LL;
int a[10];

int main()
{
    LL n;
    while(scanf("%lld%d%d%d",&n,&a[1],&a[2],&a[3]) == 4)
    {
        sort(a+1,a+4);
        LL ans = n;
        for(int i = 3; i >= 1; i--)
            n = (n * (100 - a[i])) / 100;
        printf("%lld\n",ans - n);
    }
    return 0;
}
