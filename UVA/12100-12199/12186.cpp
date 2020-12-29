#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 110000

int n, t;
int dp[N];
vector<int> G[N];

int cmp(int a, int b) {
    return dp[a] < dp[b];
}

int dfs(int pa) {
    if (dp[pa]) return dp[pa];
    if (G[pa].empty()) return dp[pa] = 1;   //¹¤ÈË
    int c = (G[pa].size() * t + 99) / 100;
    for (int i = 0; i < G[pa].size(); ++i) dfs(G[pa][i]);
    sort(G[pa].begin(), G[pa].end(), cmp);
    for (int i = 0; i < c; ++i) dp[pa] += dp[G[pa][i]];
    return dp[pa];
}

int main() {
    while (scanf("%d%d", &n, &t) != EOF && (n + t)) {
        for (int i = 0; i <= n; ++i) G[i].clear();
        for (int i = 1; i <= n; ++i) {   //½¨Ê÷
            int pa;
            scanf("%d", &pa);
            G[pa].push_back(i);
        }
        memset(dp, 0, sizeof(int) * (n + 100));
        printf("%d\n", dfs(0));
    }
    return 0;
}
