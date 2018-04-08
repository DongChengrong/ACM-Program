#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 10;
int dp[maxn];
char str[maxn];

int isPaline(int r,int l)
{
    while(l < r)
    {
        if(str[l] != str[r]) return 0;
        r--; l++;
    }
    return 1;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str + 1);
        dp[0] = 0;
        int len = strlen(str + 1);
        for(int i = 1; i <= len; i++)
        {
            dp[i] = i + 1;
            for(int j = 1; j <= i; j++)
                if(isPaline(i, j))
                {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
        }
        printf("%d\n",dp[len]);
    }
    return 0;
}
