#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define N 55
#define M 250
#define INF 0x3f3f3f3f

int vis[N];
int n, x, y;
int a[N], b[N], dp[N][M];

int check(int mid, int x, int y) {
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= x && i * a[0] <= mid; ++i) dp[0][i] = (mid - a[0] * i) / b[0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= x; ++j) {
            for (int k = 0; k <= j && k * a[i] <= mid; ++k) {
                if (dp[i -1][j - k] != -1) dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + ((mid - a[i] * k) / b[i]));
            }
        }
    }
    return dp[n - 1][x] >= y;
}

int main() {
    int T; scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        scanf("%d%d%d", &n, &x, &y);
        for (int i = 0; i < n; ++i) scanf("%d%d", &a[i], &b[i]);
        int l = 1, r = INF, res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid, x, y)) { r = mid - 1; res = mid; }
            else l = mid + 1;
        }
        printf("Case %d: %d\n", kase, res);
    }
    return 0;
}
