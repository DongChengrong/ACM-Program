#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const double C = 0.57721566490153286060651209;
const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int cnt;
LL a[maxn];

long long H( LL n ) {

    a[0] = 0;
    cnt = 1;
    LL pre = 0;
    for( LL i = 1; i <= sqrt(n); i++ )
        if(n / i != pre)
        {
            a[cnt] = i;
            pre = a[cnt++];
        }


    a[cnt] = n;
    long long res = 0;
    for( LL i = 1; i <= cnt; i++){
        res = res + ((n / a[i]) * (a[i] - a[i - 1]));
        printf("%d\n",a[i]);
    }
    return res;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int kase = 1; kase <= T; kase++)
    {
        LL n,res;
        scanf("%lld",&n);
        res = (log(n) + C) * n;
        printf("Case %d: %lld\n",kase,res);
    }
    return 0;
}
