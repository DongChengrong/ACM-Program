#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

const int maxn = 1000 + 10;
int dp[maxn][maxn];
char s1[maxn],s2[maxn];

int main()
{
    while(scanf("%s%s",s1 + 1,s2 + 1) == 2)
    {
        memset(dp,0, sizeof(dp));

        int m = strlen(s1 + 1);
        int n = strlen(s2 + 1);

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s1[i] == s2[j])
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i - 1][j]);
                else
                    dp[i][j] = max(dp[i - 1][j],dp[i][j- 1]);
            }
        }

        printf("%d\n",dp[m][n]);
    }
    return 0;
}
