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
    int T;
    LL x,m,k,c;
    scanf("%d",&T);
    for(int kase = 1; kase <= T; kase++)
    {
        scanf("%lld%lld%lld%lld",&x,&m,&k,&c);
        LL result = pow(10, m, 9 * k);
        result = (result - 1) * x % (9 * k);
        //printf("%lld\n",result);
        printf("Case #%d:\n",kase);
        if(result == 9 * c) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
