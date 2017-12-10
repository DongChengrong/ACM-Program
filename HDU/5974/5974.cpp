#include<stdio.h>

typedef long long LL;

LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    LL a,b;
    while(scanf("%lld%lld",&a,&b) == 2)
    {
        if(gcd)
    }
    return 0;
}
