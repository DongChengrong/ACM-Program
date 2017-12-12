#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

long long H( LL n ) {
    long long res = 0;
    for( LL i = 1; i <= n; i++ )
        res = res + n / i;
    return res;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int kase = 1; kase <= T; kase++)
    {
        LL n;
        scanf("%lld",&n);
        printf("%lld\n",H(n));
    }
    return 0;
}
