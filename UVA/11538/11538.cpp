#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    unsigned long long n,m;
    while(scanf("%lld %lld",&n,&m) == 2 && n)
    {
        if( n > m) swap(n, m);
        unsigned long long ans;
        ans = n * m * ( m + n - 2);
        ans += (2 * (3 * m - n -1) * n * (n - 1)) / 3;
        printf("%lld\n",ans);
    }
    return 0;
}
