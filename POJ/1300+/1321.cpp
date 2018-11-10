#include <stdio.h>
#include <string.h>

#define N 15

int n, k, cnt;
int row[N], col[N];
char G[N][N];

void dfs(int x, int cur) {
    if (cur == k) {
        ++cnt; return;
    }

    for (int i = x + 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (G[i][j] == '#' && !col[j]) {
                col[j] = 1;
                dfs(i, cur + 1);
                col[j] = 0;
            }
        }
    }
}

int main() {
    while (scanf("%d%d", &n, &k) != EOF && n != -1) {
        cnt = 0;
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for (int i = 1; i <= n; ++i) scanf("%s", G[i] + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (G[i][j] == '#' && !col[j]) {
                    col[j] = 1; dfs(i, 1); col[j] = 0;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
