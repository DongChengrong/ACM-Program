#include <stdio.h>
#include <string.h>

#define N 110000

int a[N], vis[N];

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        int cnt = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < m; ++i) {
            vis[a[i]]++;
            if (vis[a[i]] == 1) ++cnt;
            if (cnt == n) {
                printf("1");
                for (int i = 1; i <= n; ++i) {
                    vis[i]--;
                    if (vis[i] == 0) cnt--;
                }
            }
            else printf("0");
        }
        puts("");
    }
    return 0;
}
/*
3 9
1 1 1 2 2 2 3 3 3
*/
