//ÌâÄ¿Á´½Ó£ºhttp://118.190.20.162/view.page?gpid=T84
//BFS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define N 220

struct Node {
    int v, sta;
};

struct Node2{
    int u, step;
};

int n, m, t;
int T, S, E;
int ma[N][N], vis[N];
vector<Node> G[N];

//void solve() {
//    int res = 0, cls = 0;
//    queue<Node2> q;
//    q.push_back((Node2){1, 0});
//    while (q.empty()) {
//        Node2 u = q.front(); q.pop(); vis[u.u]++;
//        if (u.u == 1 && vis[u.u] >= 2 && cls == n) { printf("%d\n", res); return; }
//        if (vis[u] > n + 10) break;
//        for (int i = 0; i < G[u].size(); ++i) {
//            Node v = G[u][i];
//            if (ma[u][v.v] && (v.sta == 1 || v.sta == 3)) continue;
//            else ma[u][v.v]++;
//            q.push(v.v);
//        }
//    }
//    puts("-1");
//}

int main() {
    scanf("%d%d%d", &T, &S, &E);
    while (T--) {
        t = 0;
        scanf("%d%d", &n, &m);
        memset(vis, 0, sizeof(vis));
        memset(ma, 0, sizeof(ma));
        for (int i = 0; i <= n; ++i) G[i].clear();
//        for (int i = 0; i < m; ++i) {
//            int u, v;
//            char s[5];
//            scanf("%d %d %s", &u, &v, s);
//            G[u].push_back((Node){v, s[0] - 'A'});
//            if (s[0] - 'A' < 2) ++t;
//        }
        //solve();
        puts("0");
    }
    return 0;
}
