//ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805342720868352/problems/994805343236767744
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXN 11000

int vis[MAXN];

int is_prime(int x) {
    int i;
    int m = sqrt(x);
    for (i = 2; i <= m; ++i) if (x % i == 0) return 0;
    return 1;
}

int main() {
    int i, j;
    int sz, n, m;
    scanf("%d%d%d", &sz, &n, &m);
    while (!is_prime(sz)) ++sz;
    memset(vis, 0, sizeof(vis));
    for (i = 0; i < n; ++i) {
        int x, flag = 0; scanf("%d", &x);
        for (j = 0; j <= sz; ++j) {
            int y = (x + j * j) % sz;
            if (!vis[y]) {
                vis[y] = x;
                flag = 1;
                break;
            }
        }
        if (!flag) printf("%d cannot be inserted.\n", x);
    }
    int tot = 0;
    for (i = 0; i < m; ++i) {
        int x; scanf("%d", &x);
        for (j = 0; j <= sz; ++j) {
            ++tot;
            int y = (x + j * j) % sz;
            if (!vis[y] || vis[y] == x) break;
        }
    }
    printf("%.1f\n", (double)tot / (double)m);
    return 0;
}
