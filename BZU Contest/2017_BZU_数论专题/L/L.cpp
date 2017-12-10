#include<stdio.h>

typedef long long LL;

const LL Mod = 1000000007;
const int maxn = 10000 + 10;
LL a[maxn];

LL pow(LL a, LL b, LL m)
{
    if(b == 1) return a % m;
    if(b == 0) return 1;

    LL c = pow(a, b / 2, m);
    c = c * c % m;
    if(b & 1) c = c * a % m;

    return c;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        LL n,t,k;
        scanf("%lld%lld%lld",&n,&t,&k);

        for(LL i = 0; i < n; i++)
            scanf("%lld",&a[i]);

        k = pow(k,t,Mod);

        for(LL i =0; i < n; i++)
            printf("%lld%c",a[(i - t % n + n) % n] * k % Mod,(i == n - 1 ? '\n' : ' '));

    }
    return 0;
}
