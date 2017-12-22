#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int main()
{
    int T;
    scanf("%d",&T);
    for(int kase = 1; kase <= T; kase++)
    {
        LL n,res = 0,i;
        scanf("%lld",&n);

        for(i = 1; i <= sqrt(n); i++)
        {
            res += n / i;
            if(n / i > n / (i + 1)) res += ((n / i) - (n /  (i + 1))) * i;
        }
        i--;
        if(n / i == i) res -= i;

        printf("Case %d: %lld\n",kase,res);
    }
    return 0;
}
