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
        if(c != g) printf("sorry\n");
        else
        {
            LL b1 = b / g;
            LL a1 = a / g;
            if(x > 0)
            {
                x = x % b1;
                y = y % a1;
            }
            else
            {
                x = x % b1 + b1;
                y = y % a1 + a1;
            }
            printf("%lld %lld\n",x,y);
        }
    }
    return 0;
}
