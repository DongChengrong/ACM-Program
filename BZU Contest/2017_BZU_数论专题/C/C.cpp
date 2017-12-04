#include<stdio.h>

typedef long long LL;

LL pow(LL a, LL b)
{
    if(b == 0) return 1;
    if(b == 1) return a;

    LL c = pow(a, b / 2) % 9;
    c = c * c % 9;
    if(b & 1) c = c * a % 9;
    return c;
}

int main()
{
    LL n;
    while(scanf("%lld",&n) == 1 && n)
    {
        LL sum = pow(n,n);
        printf("%lld\n",sum == 0 ? 9 : sum);
    }
    return 0;
}
