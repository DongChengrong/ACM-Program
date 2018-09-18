/*
*题目链接：https://pintia.cn/problem-sets/994805342720868352/problems/994805343043829760
*分析：走一遍他给出的拓扑排序，若不满足输出，否则继续下一组
*时间复杂度O(KV)
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 1100

int n, m, k;

struct Graph {
    int cnt[N];
    vector<int> G[N];

    void init() {
        memset(cnt, 0, sizeof(cnt));
    }

    void build() {
        this->init();
        int u, v;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            cnt[v]++;
        }
    }
}a;

int judge(Graph a) {
        int u, v;
        int flag = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &u);
            if (a.cnt[u]) flag = 1;
            if (flag) continue;
            for (int j = 0; j < a.G[u].size(); ++j) {
                v = a.G[u][j];
                a.cnt[v]--;
            }
        }
        return flag;
    }

int main() {
    scanf("%d%d", &n, &m);
    a.build();
    scanf("%d", &k);
    int flag = 0;
    for (int i = 0; i < k; ++i) {
        if (judge(a)) {
            if (flag) printf(" ");
            else flag = 1;
            printf("%d", i);
        }
    }
    return 0;
}
