#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 220

const int dr[] = { -1, -1, 0, 0, 1, 1 };
const int dc[] = { -1, 0, -1, 1, 0, 1 };

int vis[N][N];
char G[N][N];
int n, kase = 0;

int dfs(int x, int y) {
    if (x == n - 1) return 1;
    vis[x][y] = 1;
    for (int i = 0; i < 6; ++i) {
        int xx = x + dr[i];
        int yy = y + dc[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < n && !vis[xx][yy] && G[xx][yy] == 'b') if (dfs(xx, yy)) return 1;
    }
    return 0;
}

int main() {
    while (scanf("%d", &n) !=EOF && n) {
        int ok = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; ++i) scanf("%s", G[i]);
        for (int j = 0; j < n; ++j) {
            if (!vis[0][j] && G[0][j] == 'b') if (dfs(0, j)) { ok = 1; break; }
        }
        if (ok) printf("%d B\n", ++kase); else printf("%d W\n", ++kase);
    }
    return 0;
}
