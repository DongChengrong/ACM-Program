/*
*  UVA  247
*  floyd + 建图 + DFS
*/
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define N 55

int n, m, cnt;
int g[N][N], vis[N];
vector<int> G[N];
unordered_map<string, int> ma1;
unordered_map<int, string> ma2;

int id(string s) {
    if (ma1.count(s) != 0) return ma1[s];
    ma1[s] = cnt; ma2[cnt] = s;
    ++cnt;
    return cnt - 1;
}

void init() {
    cnt = 0;
    ma1.clear(); ma2.clear();
    memset(vis, 0, sizeof(vis));
    memset(g, 0, sizeof(g));
    for (int i = 0; i < N; ++i) g[i][i] = 1;
    for (int i = 0; i < N; ++i) G[i].clear();
}

void floyd() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
            }
        }
    }
}

void build_graph() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (g[i][j] && g[j][i]) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
}

void dfs(int u, int flag) {
    if (vis[u]) return;

    vis[u] = 1;
    if (flag) cout << ", ";
    cout << ma2[u];

    for (int i = 0; i < G[u].size(); ++i) {
        dfs(G[u][i], 1);
    }

}

int main() {
    int kase = 0;
    ios_base::sync_with_stdio(false);
    while (cin >> n >> m && n) {
        init();
        cout << "Calling circles for data set " << ++kase <<":\n";
        for (int i = 0; i < m; ++i) {
            int u, v;
            string s1, s2;

            cin >> s1 >> s2;
            u = id(s1); v = id(s2);
            g[u][v] = 1;
        }

        floyd();

        build_graph();

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, 0); cout << '\n';
            }
        }
    }
    return 0;
}
