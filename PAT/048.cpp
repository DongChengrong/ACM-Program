/*
*ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805342720868352/problems/1038429908921778176
**/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 110000

int n, m;
int vis[N];
vector<int> G[N];

void build() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

int main() {
    int k;
    build();
    while (m--) {
        scanf("%d", &n);
        int ok = 1;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; ++i) {
            int u; scanf("%d", &u);
            if (!ok) continue;
            vis[u] = 1;
            for (int j = 0; j < G[u].size(); ++j) {
                int v = G[u][j];
                if (vis[v]) ok = 0;
            }
        }
        if (ok) puts("Yes");
        else puts("No");
    }
    return 0;
}
