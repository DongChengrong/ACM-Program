#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 110000

int n, root;
int pa[N], c[N];
vector<int> child[N];
vector<int> res;

void dfs(int u) {
    if (c[u]) {
        int del = 1;
        for (int i = 0; i < child[u].size(); ++i) if (!c[child[u][i]]) del = 0;
        if (del) {
            int p = pa[u];
            for (int i = 0; i < child[u].size(); ++i) {
                int v = child[u][i];
                pa[v] = p;
            }
            res.push_back(u);
        }
    }
    for (int i = 0; i < child[u].size(); ++i) dfs(child[u][i]);
}

int main() {
    while (scanf("%d", &n) != EOF) {
        res.clear();
        for (int i = 0; i <= n; ++i) child[i].clear();
        for (int i = 1; i <= n; ++i) {
            int p, cc; scanf("%d%d", &p, &cc);
            if (p == -1) { root = i; c[i] = cc;  }
            else {
                pa[i] = p; c[i] = cc; child[p].push_back(i);
            }
        }
        dfs(root);
        sort(res.begin(), res.end());
        if (res.empty()) puts("-1");
        else {
            for (int i = 0; i < res.size(); ++i)
                printf("%d%c", res[i], i == res.size() - 1 ? '\n' : ' ' );
        }
    }
    return 0;
}
