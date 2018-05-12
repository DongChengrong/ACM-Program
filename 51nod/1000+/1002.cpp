#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 1000

int a[N][N], dp[2][N];

int main() {
    int n;
    while (scanf("%d",&n) == 1) {
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                scanf("%d",&a[i][j]);
            }
        }
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[1][j] = max(dp[0][j - 1] + a[i][j], dp[0][j] + a[i][j]);
            }
            memcpy(dp[0], dp[1], sizeof(dp[0]));
        }

        int MAX = 0;
        for(int i = 1; i <= n; ++i) MAX = max(MAX, dp[0][i]);
        printf("%d\n",MAX);
    }
    return 0;
}
