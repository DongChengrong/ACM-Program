#include<stdio.h>
#include<math.h>
#include<string.h>

typedef long long LL;

const int maxn = 10000000 + 10;
const int maxp = 700000;

int vis[maxn];
int prime[maxp];

//快速幂+模运算
LL pow_mod(LL a, LL p, LL n)
{
    if(p == 0) return 1;
    if(p == 1) return a % n;

    LL ans = pow_mod(a, p / 2, n);
    ans = ans * ans % n;
    if(p & 1) ans = ans * a % n;
    return ans;
}


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        LL n;
        scanf("%lld",&n);
        printf("%lld\n",pow_mod(n % 10, n, 10));
    }
    return 0;
}