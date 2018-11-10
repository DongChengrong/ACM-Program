#include <stdio.h>
#include <string.h>

#define N 22000

int vis[N];

int main() {
    int v, n;
    while (scanf("%d", &v) != EOF) {
        scanf("%d", &n);
        memset(vis, 0, sizeof(vis));
        vis[v] = 1;
        while (n--) {
            int x; scanf("%d", &x);
            for (int j = 0; j <= v; ++j) {
                if (vis[j] && j >= x) {
                    vis[j - x] = 1;
                }
            }
        }
        int i;
        for (i = 0; i <= v; ++i) if (vis[i]) break;
        printf("%d\n", i);
    }
    return 0;
}
