//ºÚµ•π„À—
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

#define N 35
#define M 85

struct Node {
    int x, y;
};

int vis[N][M];
char G[N][M];

const int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int main() {
    int T;
    scanf("%d", &T); getchar();
    while (T--) {
        memset(vis, 0, sizeof(vis));
        int n, x = -1, y = -1;
        for (n = 0; ; ++n) {
            gets(G[n]);
            if (G[n][0] == '_') break;
            if (x != -1) continue;
            int m = strlen(G[n]);
            for (int i = 0; i < m; ++i)
                if (G[n][i] == '*') {
                    x = n, y = i;
                }
        }
        queue<Node> q;
        q.push((Node){x, y}); vis[x][y] = 1;
        while (!q.empty()) {
            Node u = q.front(); q.pop();
            G[u.x][u.y] = '#';
            for (int i = 0; i < 4; ++i) {
                Node v = u;
                v.x += dir[i][0]; v.y += dir[i][1];
                if (v.x >= 0 && v.x < n && v.y >= 0 && v.y < strlen(G[v.x]) && !vis[v.x][v.y] && G[v.x][v.y] == ' ') {
                    vis[v.x][v.y] = 1;
                    q.push(v);
                }
            }
        }
        for (int i = 0; i <= n; ++i) puts(G[i]);
    }
    return 0;
}
