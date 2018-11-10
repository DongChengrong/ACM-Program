#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 25

int pa[N];

int findset(int x) {
    return x == pa[x] ? x : pa[x] = findset(pa[x]);
}

int k, cnt, vis[N];
vector<int> G[N], path;

void init_find_union_set() {
    for (int i = 0; i < N; ++i) pa[i] = i;
}

void _union(int x, int y) {
    x = findset(x); y = findset(y);
    if (x != y) {
        pa[x] = y;
    }
}

void read_and_build() {
    int u, v;
    init_find_union_set();
    for (int i = 0; i < N; ++i) G[i].clear();
    while (scanf("%d%d", &u, &v) != EOF && (u + v)) {
        G[u].push_back(v); G[v].push_back(u);
        _union(u, v);
    }
    for (int i = 0; i < N; ++i) sort(G[i].begin(), G[i].end());
    memset(vis, 0, sizeof(vis));
    cnt = 0; path.clear(); path.push_back(1); vis[1] = 1;
}

void print_path(vector<int> path) {
    int len = path.size();
    for (int i = 0; i < len; ++i) printf("%d%c", path[i], i == len -1 ? '\n' : ' ');
}

void dfs(int u, vector<int> path) {
    if (u == k) {
        ++cnt; print_path(path);
    }
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (!vis[v]) {
            path.push_back(v); vis[v] = 1;
            dfs(v, path);
            path.pop_back();
            vis[v] = 0;
        }
    }
}

int main() {
    int kase = 0;
    while (scanf("%d", &k) != EOF) {
        printf("CASE %d:\n", ++kase);
        read_and_build();
        if (findset(1) == findset(k)) dfs(1, path);
        printf("There are %d routes from the firestation to streetcorner %d.\n", cnt, k);
    }
    return 0;
}
