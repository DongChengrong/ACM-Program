#include<stdio.h>
#include<math.h>

typedef long long LL;

int is_prime(LL n)
{
    if(n <= 1) return 0;
    LL m = floor(sqrt(n) + 0.5);
    for(LL i = 2; i <= m; i++)
        if(n % i == 0) return 0;
    return 1;
}

LL pow(LL a, LL b, LL m)
{
    if(b == 0) return 1;
    if(b == 1) return a % m;

    LL res = pow(a, b / 2, m);
    res = res * res % m;
    if(b & 1) res = res * a % m;
    return res % m;
}

int main()
{
    LL n;
    while(scanf("%lld",&n) == 1 && n)
    {
        int ok = 1;

        if(is_prime(n)) ok = 0;

        for(LL x = 2; x <= n - 1; x++)
        {
            if(!ok) break;
            LL a = pow(x,n,n) % n;
            LL b = x % n;
            if(a != b)
            {
                ok = 0;
                break;
            }
        }

        if(ok) printf("The number %lld is a Carmichael number.\n",n);
        else printf("%lld is normal.\n",n);
    }
    return 0;
}
