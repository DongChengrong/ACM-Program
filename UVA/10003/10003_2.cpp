#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int INF = 1000000;
const int maxn = 50 + 10;
int c[maxn],d[maxn][maxn],n;

int dp(int i, int j)
{
    //当 >= j - 1时无法剪切，返回值0
    if(i >= j - 1) return 0;
    if(d[i][j] != -1) return d[i][j];

    int &ans = d[i][j];
    ans = INF;

    for(int k = i + 1; k < j; k++)
        ans = min(ans, dp(i, k) + dp(k, j));

    return ans += (c[j] - c[i]);
}

int main()
{
    int L;
    while(scanf("%d",&L) == 1 && L)
    {
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
            scanf("%d",&c[i]);
        c[0] = 0; c[n + 1] = L;

        memset(d,-1,sizeof(d));

        //得到最优解
        int ans = dp(0, n + 1);

        printf("The minimum cutting is %d.\n",ans);
    }
    return 0;
}
