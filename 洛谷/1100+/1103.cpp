#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define N 210
#define INF 0x3f3f3f3f

int n, k;
int dp[2][N];

struct Node {
    int h, w;
    bool operator < (const Node &a) const {
        return h < a.h;
    }
}a[N];

int main() {
    while (scanf("%d%d",&n, &k) == 2) {
        for (int i = 1; i <= n; ++i) scanf("%d%d",&a[i].h, &a[i].w);

        sort(a + 1, a + 1 + n);

        memset(dp[0], 0, sizeof(dp[0]));
        memset(dp[1], INF, sizeof(dp[1]));

        for (int j = 2; j <= n - k; ++j) {
            for (int i = j; i <= n; ++i) {
                for (int k = j - 1; k < i; ++k) {
                    dp[1][i] = min(dp[1][i], dp[0][k] + abs(a[i].w - a[k].w));
                    //printf("%d %d %d\n",i, j, dp[1][i]);
                }
            }
            memcpy(dp[0], dp[1], sizeof(dp[0]));
            memset(dp[1], INF, sizeof(dp[1]));
        }

        int MIN = INF;
        for (int i = 1; i <= n; ++i) MIN = min(MIN, dp[0][i]);
        printf("%d\n", MIN);
    }
    return 0;
}
