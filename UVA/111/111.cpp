#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 20 + 10;
int a[maxn],b[maxn],d[maxn][maxn];
int n,t;

int dp(int i,int j)
{
    memset(d,0,sizeof(d));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(a[i] == b[j]) d[i][j] = d[i - 1][j - 1] + 1;
            else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    return d[n][n];
}

int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&t);
        a[t] = i;
    }
    while(scanf("%d",&t) == 1)
    {
        b[t] = 1;
        for(int i = 2; i <= n; i++)
        {
            scanf("%d",&t);
            b[t] = i;
        }
        printf("%d\n",dp(n,n));
    }
    return 0;
}
