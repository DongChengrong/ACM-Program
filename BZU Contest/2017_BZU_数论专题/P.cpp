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
    LL x,y,d,a,n;
    int T;
    scanf("%d",&T);
    for(int kase = 1; kase <= T; kase++)
    {
        scanf("%lld%lld",&a,&n);
        gcd(a,n,d,x,y);
        if(d != 1) printf("Not Exist\n");
        else
        {
            while(x > n) x -= n;
            while(x <= 0) x += n;
            printf("%lld\n",x);
        }
    }
    return 0;
}
