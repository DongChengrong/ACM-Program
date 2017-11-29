#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long long LL;

void gcdEx(LL a,LL b,LL &d,LL &x,LL &y)
{
    if(!b)
    {
        x = 1; y = 0;
        d = a;
    }
    else
    {
        gcdEx(b,a % b,d,y,x);
        y -= x * (a / b);
    }
}

int main()
{
    LL m,n,x,y,l;
    while(scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l) == 5)
    {
        if(m < n)
        {
            swap(x,y);
            swap(m,n);
        }
        LL g;
        LL a = m - n;
        LL b = l;
        LL c = y - x;
        gcdEx(a,b,g,x,y);
        if(c % g) printf("Impossible\n");
        else
        {
            x = x * c / g;
            LL b1 = b / g;
            if(x > 0) x = x % b1;
            else x = x % b1 + b1;
            printf("%lld\n",x);
        }
    }
    return 0;
}
