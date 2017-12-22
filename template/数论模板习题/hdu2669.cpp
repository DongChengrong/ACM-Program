#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long long LL;

void gcd(LL a, LL b, LL &d, LL &x, LL &y)
{
    if(!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        gcd(b,a%b,d,y,x);
        y -= x * (a / b);
    }
}

int main()
{
    LL x,y,a,b,l;
    while(scanf("%lld%lld",&a,&b) == 2)
    {
        LL d,x,y;
        gcd(a,b,d,x,y);
        if(d != 1) printf("sorry\n");
        else
        {
            while(x > b) x -= b;
            while(x < 0) x += b;
            printf("%lld %lld\n",x,(1 - a * x) / b);
        }
    }
    return 0;
}