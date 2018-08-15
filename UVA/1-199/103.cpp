/*
*需要打印路径的矩形嵌套问题
*作者：董成荣
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define N 110

int n, k;

struct Node {
    int a[N];
    void Sort() {
        sort(a, a + k);
    }
};


int dp[N], pre[N];
Node a[N];

bool in(int u, int v) {
    for (int i = 0; i < k; ++i) {
        if (a[v].a[i] >= a[u].a[i]) return false;
    }
    return true;
}

void init() {
    memset(dp, 0, sizeof(dp));
    memset(pre, -1, sizeof(pre));
}

int dfs(int u) {
    if (dp[u]) return dp[u];

    int &ans = dp[u];
    dp[u] = 1;

    for (int v = 1; v <= n; ++v) {
        if (u == v) continue;
        if (in(u, v)) {
            int tmp = dfs(v);
            if (ans < 1 + tmp) {
                ans = tmp + 1;
                pre[u] = v;
            }
        }
    }

    return ans;
}

int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        init();
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < k; ++j) scanf("%d", &a[i].a[j]);
            a[i].Sort();
        }
        int index = 1;
        for (int i = 1; i <= n; ++i) {
            dfs(i);
            if (dp[i] > dp[index]) index = i;
        }
        vector<int> ans;
        while (index != -1) {
            ans.push_back(index);
            index = pre[index];
        }
        reverse(ans.begin(), ans.end());
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); ++i) printf("%d%c", ans[i],i == ans.size() - 1 ? '\n' : ' ');
    }
    return 0;
}
