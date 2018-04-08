#include<stdio.h>
#include<vector>
using namespace std;

#define N 1000000010
#define MOD 10000007

typedef long long LL;

vector<LL> a;

void init()
{
    a.clear();
    a.push_back(0); a.push_back(233);
    LL x = 233;
    for(int i = 2; i < N; i++)
        a.push_back((x * 10 + 3) % MOD);
}

int main()
{
    LL n,m;
    while(scanf("%lld%lld",&n,&m) == 2)
    {
        init();
        for(int i = 0; i <= m; i++)
            printf("%lld\n ",a[i]);
        putchar('\n');
        for(int i = 1; i <= n; i++)
        {
            LL x;
            scanf("%lld",&x);
            a[0] = x % MOD;
            for(LL i = 0; i <= m; i++)
                printf("%lld ",a[i]);
            putchar('\n');
            for(LL j = 1; j <= m; j++)
            {
                a[j] = (a[j - 1] + a[j]) % MOD;
            }
        }

        printf("%lld\n",a[m] % MOD);
    }
    return 0;
}
