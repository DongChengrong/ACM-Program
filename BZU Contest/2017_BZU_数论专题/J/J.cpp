#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

typedef long long LL;
const int maxn = 40000000;
int prime[maxn],a[maxn + 10];

int is_prime(LL n)
{
    if(n <= 1) return 0;
    LL m = floor(sqrt(n) + 0.5);
    for(LL i = 2; i <= m; i++)
        if(n % i == 0) return 0;
    return 1;
}

void init()
{
    LL cnt = 1;
    for(LL i = 1; i <= maxn; i++)
    {
        prime[i] = is_prime(i);
        if(!prime[i]) a[i] = 0;
        else
        {
            a[i] = prime[cnt];
            if(prime[i] && i >= 1000000)
            cnt++;
        }
    }
}

int main()
{
    int n;
    init();
    while(scanf("%d",&n) == 1)
    {
        for(LL i = n; ; i++)
            if(a[i])
            {
                printf("%lld\n",i);
                break;
            }
    }
    return 0;
}
