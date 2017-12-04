#include<stdio.h>

typedef long long LL;

void gcdEx(LL a, LL b, LL &d, LL &x, LL &y)
{
    if(!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        gcdEx(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

int main()
{
    LL a, b, c = 1;
    while(scanf("%lld%lld",&a,&b) == 2)
    {
        LL x,y,g;
        gcdEx(a,b,g,x,y);
        if(g != 1) printf("sorry\n");
        else
        {
            int b1 = b / g;
            int a1 = a / g;
            while(x < 0) x += b;
               y = (1 - x * a) / b;

            printf("%lld %lld\n",x,y);
        }
    }
    return 0;
}
