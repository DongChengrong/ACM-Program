#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 110

int n, m;
int a[N][N];

int main() {
    int T;

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &T);
    while (T--) {
        memset(a, 0, sizeof(a));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i][j]) res += 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m + 1; ++j) {
                res += abs(a[i][j] - a[i][j - 1]);
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n + 1; ++j) {
                res += abs(a[j][i] - a[j - 1][i]);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
