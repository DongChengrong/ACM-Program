#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

#define N 35

int vis[N];
vector<int> G[N];

void dfs(int u) {
    vis[u] = 1;
    for (int v : G[u]) if (!vis[v]) dfs(v);
}

int main() {
    string line;
    int T; cin >> T; getchar();
    getline(cin, line);
    while (T--) {
        getline(cin, line);
        char c = line[0];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < N; ++i) G[i].clear();
        while (getline(cin, line)) {
            if (line == "") break;
            int u = line[0] - 'A';
            int v = line[1] - 'A';
            G[u].push_back(v); G[v].push_back(u);
        }
        int cnt = 0;
        for (int i = 0; i <= (c - 'A'); ++i) if (!vis[i]) { dfs(i); ++cnt;}
        printf("%d\n", cnt);
        if (T) puts("");
    }
    return 0;
}
