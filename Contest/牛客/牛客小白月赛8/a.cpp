#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

#define N 110000

vector<int> G[N];

int dfs(int u, int fa, int cnt) {
    for (int i = 0; i < G[u].size(); ++i) {
        if (fa != G[u][i]) cnt += dfs(G[u][i], u, 1);
    }
    return cnt;
}

int main() {
    int n, m;

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < N; ++i) G[i].clear();
        set<int> s;
        int st;
        while (m--) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v); G[v].push_back(u);
            s.insert(u); s.insert(v); st = u;
        }
        if ( dfs(st, -1, 1) == n) {
            int i = 1;
            int n = s.size();
            for (auto it = s.begin(); it != s.end(); ++it) {
                printf("%d", *it);
                if (i == n) puts("");
                else printf(" ");
                ++i;
            }
        }
    }
    return 0;
}
