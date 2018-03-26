#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 7;

LL num[maxn],dp[maxn];

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        memset(num,0,sizeof(num));
        memset(dp,0,sizeof(dp));

        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d",&x);
            num[x] += x;
        }

        dp[1] = num[1]; dp[2] = max(num[1],num[2]);

        for(int i = 3; i < maxn; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + num[i]);

        cout << dp[100000] << endl;
    }
    return 0;
}
