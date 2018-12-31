//#include <stdio.h>
//#include <string.h>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//#define N 110
//
//int n, m, id, sum;
//int vis[N], a[N], vis2[N];
//vector<int> G[N];
//
//int dfs(int u) {
//    if (vis[u]) return vis[u];
//    for (int v : G[u]) {
//        if (vis2[v]) continue;
//        vis2[v] = 1;
//        vis[u] = max(vis[u], dfs(v));
//        vis2[v] = 0;
//    }
//    if (vis[u] == 0) return (vis[u] = a[u]);
//    return (vis[u] = vis[u] + a[u]);
//}
//
//void dfs2(int u, int tot) {
//    for (int v : G[u]) {
//        if (vis[v] == tot) {
//            if (vis[v] == a[v]) {
//                id = v; return;
//            }
//            dfs2(v, tot - a[v]);
//        }
//    }
//}
//
//int main() {
//
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//
//    int T, kase = 0;
//    scanf("%d", &T);
//    while (T--) {
//        sum = id = 0;
//        scanf("%d%d", &n, &m);
//        for (int i = 0; i < n; ++i) {
//            scanf("%d", &a[i]); vis2[i] = vis[i] = 0;
//            G[i].clear();
//        }
//        for (int i = 0; i < m; ++i) {
//            int u, v;
//            scanf("%d%d", &u, &v);
//            G[u].push_back(v);
//        }
//        vis[0] = 0;
//        dfs(0); dfs2(0, vis[0] - a[0]);
//        printf("Case %d: %d %d\n", ++kase, vis[0], id);
//    }
//    return 0;
//}
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 110

int n, m, id, sum;
int vis[N], a[N], vis2[N];
vector<int> G[N];

int cmp(int x, int y) {
    return a[x] > a[y];
}

void dfs(int u, int tot) {
    if (G[u].size() == 0) {
        sum = tot; id = u; return;
    }
    int v = G[u][0];
    dfs(v, tot + a[v]);
}

int main() {

    int T, kase = 0;
    scanf("%d", &T);
    while (T--) {
        sum = id = 0;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]); vis2[i] = vis[i] = 0;
            G[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }
        for (int i = 0; i < n; ++i) {
            sort(G[i].begin(), G[i].end(), cmp);
        }
        vis[0] = 0;
        dfs(0, a[0]);
        printf("Case %d: %d %d\n", ++kase, sum, id);
    }
    return 0;
}
