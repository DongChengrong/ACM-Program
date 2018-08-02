#include <stdio.h>
#include <string.h>

#define N 50

int n;
char names[N][N];
double d[N][N][N], p[N][N];

void init() {
    n = 15;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= n; ++k) {
                d[i][j][k] = -1;
            }
        }
    }
    for (int i = 0; i <= n; ++i) {
        scanf("%s", names[i]);
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            int P;
            scanf("%d", &P);
            p[i][j] = P / 100.0;
        }
    }
}

double dp(int k, int l, int r) {
    double &ans = d[k][l][r];
    if (ans >= 0) return ans;
    if (r - l == 1) return ans = p[k][k == l ? r : l];

    ans = 0;
    double tmp;
    int m = (l + r) >> 1;
    if (k <= m) {
        tmp = dp(k, l, m);
        for (int i = m + 1; i <= r; ++i) {
            ans += tmp * p[k][i] * dp(i, m + 1, r);
        }
    } else {
        tmp = dp(k, m + 1, r);
        for (int i = l; i <= m; ++i) {
            ans += tmp * p[k][i] * dp(i, l, m);
        }
    }
    return ans;
}

int main() {
    init();
    for (int i = 0; i <= n; ++i) {
        printf("%-10s p=%.2f%\n", names[i], dp(i, 0, n) * 100);
    }
    return 0;
}
