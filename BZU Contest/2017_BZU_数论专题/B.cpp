#include<stdio.h>

typedef long long LL;

LL pow(LL a, LL b, LL n)
{
    if(b == 0) return 1;
    if(b == 1) return a;

    LL c = pow(a, b / 2, n) % n;
    c = c * c % n;
    if(b & 1) c = c * a % n;
    return c;
}

int main()
{
    LL n;
    while(scanf("%lld",&n) == 1 && n)
    {
        LL result = (pow(2,n - 1,n) + 1) % n;
        printf("%lld\n", result);
    }
    return 0;
}
