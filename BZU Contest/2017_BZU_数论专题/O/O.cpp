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
    LL x,y,m,n,l;
    while(scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l) == 5)
    {
        if(m < n)
        {
            swap(m,n);
            swap(x,y);
        }

        LL b = l;
        LL a = m - n;
        LL c = y - x;
        LL d,x,y;
        gcd(a,b,d,x,y);
        if(c % d) printf("Impossible\n");
        else
        {
            x = x * c / d;
            LL b1 = b / d;
            if(x > 0)
            {
                x = x % b1;
            }
            else
            {
                x = x % b1 + b1;
            }
            printf("%lld\n",x);

        }
    }
    return 0;
}
