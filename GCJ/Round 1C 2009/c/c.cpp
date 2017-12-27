#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxp = 100 + 10;
int q[maxp],dp[maxp][maxp];

int main()
{
    int N,Q,P;

    freopen("C-large-practice.in", "r", stdin);
    freopen("C-large-practice.out", "w", stdout);

    scanf("%d",&N);
    for(int kase = 1; kase <= N; kase++)
    {
        scanf("%d %d",&P,&Q);

        for(int i = 1; i <= Q; i++)
            scanf("%d",&q[i]);
        q[0] = 0;
        q[Q + 1] = P + 1;

        for(int i = 0; i < Q; i++)
            dp[i][i + 1] = 0;

        for(int w = 2; w <= Q + 1; w++)
        {
            for(int i = 0; i + w <= Q + 1; i++)
            {
                int j =  i + w;
                int t = INF;
                for(int k = i + 1; k < j; k++)
                    t = min(t, dp[i][k] + dp[k][j]);
                dp[i][j] = t + q[j] - q[i] - 2;
            }
        }

        printf("Case #%d: %d\n",kase,dp[0][Q + 1]);
    }
    return 0;
}
