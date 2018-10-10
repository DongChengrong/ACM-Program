#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 200200

int n, k, h;
int ind[N];
vector<int> G[N];

void init(int n) {
    memset(ind, 0, sizeof(ind));
    for (int i = 0; i <= n; ++i) G[i].clear();
}

void build() {
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

int dfs(int u, int fa) {  //当前节点，父节点，当前高度
    int cnt = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        if (G[u][i] != fa) cnt += dfs(G[u][i], u);
    }
    return ind[u] = cnt;
}

int main() {
    int T;

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &T);
    while (T--) {
        int res = 0;
        scanf("%d%d", &n, &k);
        init(n);
        build();
        dfs(1, -1);
        for (int i = 1; i <= n; ++i) {
            if (ind[i] >= k && n - ind[i] >= k) ++res;
        }
        printf("%d\n", res);
    }
    return 0;
}
