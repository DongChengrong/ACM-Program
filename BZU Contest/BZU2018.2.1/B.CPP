#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n) == 2)
    {
        int ans;
        if((n & 1) == 0) ans = n / 2 * m;
        else if((m & 1) == 0) ans = m / 2 * n;
        else ans = m / 2 * n + n / 2;
        printf("%d\n",ans);
    }
    return 0;
}
