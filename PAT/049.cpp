//ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805342720868352/problems/994805342821531648
#include <stdio.h>
#include <string.h>

#define N 1100

int a[N];
int m, n;

int check(int i, int state) {
    if (2 * i <= n) {
        return (state ? (a[i] >= a[i * 2] && (i * 2 + 1 > n || (a[i] >= a[i * 2 + 1]))) :\
        (a[i] <= a[i * 2] && (i * 2 + 1 > n || (a[i] <= a[i * 2 + 1]))) ) && check(i * 2, state) \
        && check(i * 2 + 1, state);
    }
    return 1;
}

void dfs(int u, int state) {
    if (u > n) return;
    dfs(u * 2, 1);
    dfs(u * 2 + 1, 1);
    printf("%d%c", a[u], state ? ' ' : '\n');
}

int main() {
    scanf("%d%d", &m, &n);
    while (m--) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        if (check(1, 0)) {
            puts("Min Heap");
        } else if (check(1, 1)) {
            puts("Max Heap");
        } else {
            puts("Not Heap");
        }
        dfs(1, 0);
    }
    return 0;
}
