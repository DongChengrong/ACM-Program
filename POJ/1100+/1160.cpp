#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 500
#define INF 0x3f3f3f3f

int n, K;
int a[N], w[N][N], dp[N][N];

void init(int n) {
    memset(w, 0, sizeof(w));
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            w[i][j] = w[i][j - 1] + a[j] - a[(i + j) >> 1];
            //printf("%d %d %d\n", i, j, w[i][j]);
        }
    }
}

int main() {
    while (scanf("%d%d",&n, &K) == 2) {
        for (int i = 1; i <= n; ++i) scanf("%d",&a[i]);
        init(n);

        memset(dp, INF, sizeof(dp));
        for (int i = 1; i <= n; ++i) dp[i][i] = 0;
        for (int i = 2; i <= n; ++i) dp[i][1] = w[1][i];

        for (int j = 2; j <= K; ++j) {
            for (int i = 2; i <= n; ++i) {
                for (int k = j - 1; k < i; ++k) {
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] + w[k + 1][i]);
                    //printf("%d %d %d\n", i, j, dp[i][j]);
                }
            }
        }
        printf("%d\n", dp[n][K]);
    }
    return 0;
}
