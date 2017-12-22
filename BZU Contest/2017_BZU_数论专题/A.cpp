#include<stdio.h>

typedef long long LL;

LL pow(LL a, LL b)
{
    if(b == 0) return 1;
    if(b == 1) return a;

    LL c = pow(a, b / 2) % 10;
    c = c * c % 10;
    if(b & 1) c = c * a % 10;
    return c;
}

int main()
{
    int T;
    LL n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        printf("%lld\n",pow(n % 10,n));
    }
    return 0;
}
