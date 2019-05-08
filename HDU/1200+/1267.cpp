#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 25

typedef long long ll;

ll dp[N][N];

void init() {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 20; ++i) dp[i][0] = 1;
    for (int i = 1; i <= 20; ++i) {
        for (int j = 1; j <= 20; ++j) {
            if (i < j) break;
            dp[i][j] = dp[i][j - 1];
            if (i != j) dp[i][j] = dp[i][j] + dp[i - 1][j];
        }
    }
}

int main() {
    init();
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) printf("%lld\n", dp[n][m]);
    return 0;
}
