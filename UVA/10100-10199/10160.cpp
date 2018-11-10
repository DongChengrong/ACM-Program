#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

#define N 40

int n, m;
int vis[N];
vector<int> G[N];

void init() {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < N; ++i) G[i].clear();
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF && n) {
        init();
        while (int i = 0; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }
    return 0;
}
