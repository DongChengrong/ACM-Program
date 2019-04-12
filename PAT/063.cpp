//ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/1101496891327721472/problems/1109434347793534976
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define N 550

int n, m, k;
vector<int> G[N];
int vis[N];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v); G[v].push_back(u);
    }
    int t; scanf("%d", &t);
    while (t--) {
        set<int> s;
        for (int i = 1; i <= n; ++i) { scanf("%d", &vis[i]); s.insert(vis[i]); }
        int ok = 1;
        if (s.size() != k) ok = 0;
        for (int i = 1; i <= n; ++i) {
            if (!ok) break;
            for (int v : G[i]) {
                if (vis[i] == vis[v]) { ok = 0; break; }
            }
        }
        if (ok) puts("Yes");
        else puts("No");
    }
    return 0;
}
