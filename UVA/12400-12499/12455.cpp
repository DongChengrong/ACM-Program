#include <stdio.h>

#define N 50

int a[N];

int dfs(int i, int cur, int x, int n) {
    if (cur == x) return 1;
    if (cur > x) return 0;
    if (i > n) return 0;
    if (dfs(i + 1, cur + a[i], x, n)) return 1;
    if (dfs(i + 1, cur, x, n)) return 1;
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, x, i;
        scanf("%d%d", &x, &n);
        for (i = 0; i < n; ++i) scanf("%d", &a[i]);
        if (dfs(0, 0, x, n)) puts("YES");
        else puts("NO");
    }
    return 0;
}
