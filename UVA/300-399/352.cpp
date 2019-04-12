#include <stdio.h>
#include <string.h>

#define N 50

int n;
int vis[N][N];
char G[N][N];

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int xx = x + i, yy = y + j;
            if (xx >= 0 && xx < n && yy >= 0 & yy < n && !vis[xx][yy] && G[xx][yy] == '1')
                dfs(xx, yy);
        }
    }
}

int main() {
    int kase = 0;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%s", G[i]);
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j] && G[i][j] == '1') { dfs(i, j); ++cnt; }
            }
        }
        printf("Image number %d contains %d war eagles.\n", ++kase, cnt);
    }
    return 0;
}
