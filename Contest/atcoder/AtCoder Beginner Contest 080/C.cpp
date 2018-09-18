#include<stdio.h>
#include<string.h>
#include <iostream>
#include<algorithm>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100 + 10;
LL F[maxn][maxn];
LL P[maxn][maxn];
LL D[maxn];

int main()
{
    LL n;
    while(scanf("%lld",&n) == 1)
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= 10; j++)
                scanf("%lld",&F[i][j]);

        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= 10; j++)
                scanf("%lld",&P[i][j]);

        LL Max = -1 * INF;
        for(int s = 1; s < (1 << 10); s++)
        {
            for(int i = 1; i <= n; i++)
            {
                D[i] = 0;
                for(int j = 1; j <= 10; j++)
                {
                    if((F[i][j] << (j - 1)) & s) D[i]++;
                }
            }

            LL ans = 0;
            for(int i = 1; i <= n; i++)
                ans += P[i][D[i]];

            Max = max(Max,ans);
        }
        cout<< Max <<endl;
    }
}
