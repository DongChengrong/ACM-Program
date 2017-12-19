#include<stdio.h>

typedef long long LL;

LL pow(LL a, LL b, LL Mod)
{
    if(b == 1) return a % Mod;
    if(b == 0) return 1;

    LL c = pow(a, b / 2, Mod);
    c = c * c % Mod;
    if(b & 1) c = c * a % Mod;

    return c;
}

//导出公式res = (n ^ k) * k / n * sum
//即res = (n ^ (k - 1)) * k * sum
// sum = a[0] + a[1] + a[2] + ... + a[n - 1]
int main()
{
    int T;
    scanf("%d",&T);
    for(int kase = 1; kase <= T; kase++)
    {
        LL sum = 0;
        LL n,k,Mod;

        scanf("%lld%lld%lld",&n,&k,&Mod);

        for(LL i = 0; i < n; i++)
        {
            LL x;
            scanf("%lld",&x);
            sum += x;
        }

        sum = ( pow(n,k - 1,Mod) % Mod * k ) % Mod * sum;

        printf("Case %d: %lld\n",kase,sum % Mod);

    }
    return 0;
}
