#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 110

int dp[N];
int w[N], c[N], num[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i) scanf("%d%d%d", &w[i], &c[i], &num[i]);
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < num[i]; ++j) {
                for (int k = n; k >= w[i]; --k) {
                    dp[k] = max(dp[k], dp[k - w[i]] + c[i]);
                }
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
