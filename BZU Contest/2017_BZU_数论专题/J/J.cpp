#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
using namespace std;

typedef long long LL;
const int maxn = 1500000;
int prime[maxn + maxn],tmp[maxn],a[maxn + 10];

void init()
{
    int cnt = 1;
    a[1] = 0, a[2] = 1;
    for(LL i = 3; i <= maxn; i++)
    {
        if(i % 2 ) a[i] = 1;
        else a[i] = 0;
    }
    for(int i = 3; i <= sqrt(maxn); i++)
    {
        if(a[i])
        {
            for(LL j = i * 2; j <= maxn; j += i)
                a[j] = 0;
        }
    }
    LL num = 1;
    for(LL i = 1; i <= maxn; i++)
        if(a[i]) tmp[num++] = i;
    memset(prime,0,sizeof(prime));
    for(LL i = 1; i < num; i++)
        if(a[i]) prime[tmp[i]] = 1;
}

int main()
{
    int n;
    init();
    while(scanf("%d",&n) == 1)
    {
        for(LL i = n; ; i++)
            if(prime[i])
            {
                printf("%lld\n",i);
                break;
            }
    }
    return 0;
}
