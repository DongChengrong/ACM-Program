//题目链接：https://pintia.cn/problem-sets/994805148990160896/problems/994805156657348608
//犯了一个低级错误，白白的错了两次
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 550
#define INF 0x3f3f3f3f

struct Edge {
    int u, v, w;
    bool operator < (const Edge &u) const {
        return w < u.w;
    }
};

int n, m;
int pa[N], cost[N];
vector<int> res;
vector<Edge> use, repair;

int findset(int x) {
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

int same(int x, int y) {
    x = findset(x);
    y = findset(y);
    return x == y;
}

void _union(int x, int y) {
    x = findset(x);
    y = findset(y);
    if (x != y) pa[x] = y;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, w, s;
        scanf("%d%d%d%d", &u, &v, &w, &s);
        if (s) use.push_back((Edge){u, v, w});
        else repair.push_back((Edge){u, v, w});
    }
    sort(repair.begin(), repair.end());
    for (int i = 1; i <= n; ++i) {
        int cnt = n - 1, sum = 0;;
        for (int j = 0; j <= n; ++j) pa[j] = j;
        for (Edge e : use) {
            if (e.u != i && e.v != i) {
                if (!same(e.u, e.v)) {
                    _union(e.u, e.v);
                    --cnt;
                }
            }
        }
        for (Edge e : repair) {
            if (cnt == 1) break;
            if (e.u != i && e.v != i && !same(e.u, e.v)) {
                _union(e.u, e.v);
                sum += e.w; --cnt;
            }
        }
        cost[i] = cnt == 1 ? sum : INF;
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (cost[i] > sum) {
            res.clear(); sum = cost[i];
            res.push_back(i);
        } else if (cost[i] == sum) res.push_back(i);
    }
    if (sum == 0) { puts("0"); return 0; }
    for (int i = 0; i < res.size(); ++i) {
        printf("%d%c", res[i], i == res.size() - 1 ? '\n' : ' ');
    }
    return 0;
}
