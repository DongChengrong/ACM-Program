//前缀和取模
#include <stdio.h>
#include <string.h>

#define N 110000
#define M 5500

int sum[N], vis[M];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, flag = 0;
        memset(sum, 0, sizeof(sum));
        memset(vis, 0, sizeof(vis));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            sum[i] = sum[i - 1] + x;
            if (sum[i] % m == 0) flag = 1;
            else {
                vis[sum[i] % m]++;
                if (vis[sum[i] % m] > 1) flag = 1;
            }
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
