#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 550

int n, m;
int a[N][N];
int vis[N][N], vis2[N][N];

void print() {
    puts("TAK");
    for (int i = 0; i <n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vis[i][j]) printf("%d", j + 1);
        }
        if (i == n - 1) puts(""); else printf(" ");
    }
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        int cur = -1;
        memset(vis2, 0, sizeof(vis2));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <m; ++j) {
                scanf("%d", &a[i][j]);
            }
            if (i == 0) cur = a[i][0];
            else cur = cur ^ a[i][0];
            vis[i][0] = vis2[i][0] = 1;
        }
        if (cur) print();
        else {
            int ok = 0;
            for (int i = 0; i < n; ++i) {
                int tmp = cur ^ a[i][0]; vis[i][0] = 0;
                for (int j = 0; j < m; ++j) {
                    if (!vis2[i][j]) {
                        vis2[i][j] = 1;
                        tmp = tmp ^ a[i][j];
                        if (tmp) { ok = 1; vis[i][j] = 1; goto LOOP; }
                        tmp = tmp ^ a[i][j];
                    }
                }
                vis[i][0] = 1;
            }
            LOOP:;
            if (ok) print(); else puts("NIE");
        }
    }
    return 0;
}
