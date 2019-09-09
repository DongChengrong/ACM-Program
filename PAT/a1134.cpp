// problem link : https://pintia.cn/problem-sets/994805342720868352/problems/994805346428633088
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define N 11000

int n, m, cnt = 0;
int ma[N];
vector<int> G[N];
unordered_map<int, int> ma1;

int id(int u, int v) {
    int num = u * N + v;
    if (ma1[num]) return ma1[num];
    else return ma1[num] = ++cnt;
}

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(id(u, v));
        G[v].push_back(id(u, v));
    }
}

void solve() {
    int k;
    scanf("%d", &k);
    while (k--) {
        int num;
        memset(ma, 0, sizeof(int) * (n + 10));
        scanf("%d", &num);
        while (num--) {
            int tmp;
            scanf("%d", &tmp);
            for (int i = 0; i < G[tmp].size(); ++i) {
                ma[G[tmp][i]] = 1;
            }
        }
        int ok = 1;
        for (int i = 1; i <= m; ++i) {
            if (!ma[i]) ok = 0;
        }
        if (ok) puts("Yes");
        else puts("No");
    }
}

int main() {
    read();
    solve();
    return 0;
}
