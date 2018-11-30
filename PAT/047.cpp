#include <stdio.h>
#include <string.h>
#include <unordered_map>

using namespace std;

#define N 11000

int n, m;
int in[N], pre[N];
unordered_map<int, int> ma;

void dfs(int l, int r, int root, int u, int v) {
    if (l > r) return;
    int pos = ma[pre[root]];
    int pos_u = ma[u];
    int pos_v = ma[v];
    if (pos_u == pos) printf("%d is an ancestor of %d.\n", u, v);
    else if (pos_v == pos) printf("%d is an ancestor of %d.\n", v, u);
    else if ((pos_u < pos && pos_v > pos) || (pos_u > pos && pos_v < pos))
        printf("LCA of %d and %d is %d.\n", u, v, in[pos]);
    else if (pos_u < pos && pos_v < pos) dfs(l, pos - 1, root + 1 ,u, v);
    else if (pos_u > pos && pos_v > pos) dfs(pos + 1, r, root + (pos - l + 1), u, v);
}

int main() {
    ma.clear();
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &in[i]);
        ma[in[i] ] = i;
    }
    for (int i = 1; i <= n; ++i) scanf("%d", &pre[i]);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (!ma[u] && !ma[v]) printf("ERROR: %d and %d are not found.\n", u, v);
        else if (!ma[u] || !ma[v]) printf("ERROR: %d is not found.\n", ma[u] ? v : u);
        else dfs(1, n, 1, u, v);
    }
    return 0;
}
