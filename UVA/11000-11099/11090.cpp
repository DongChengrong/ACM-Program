//bellman判断负环 + 二分枚举
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define N 55

struct Edge {
    int u, v;
    double w;
};

struct Bellman{

    int n;
    double d[N];
    int inq[N];
    int cnt[N];
    vector<Edge> edges;
    vector<int> G[N];

    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; ++i) G[i].clear();
        edges.clear();
    }

    void addEdge(int u, int v, double w) {
        edges.push_back((Edge){u, v, w});
        G[u].push_back(edges.size() - 1);
    }

    void print_edges() {
        for (int i = 0; i < edges.size(); ++i)
            printf("%d %d %.2f\n", edges[i].u, edges[i].v, edges[i].w);
    }

    bool negativeCycle() {
        //print_edges();
        //判断负环初始化
        queue<int> q;
        memset(cnt, 0, sizeof(cnt));
        memset(inq, 0, sizeof(inq));
        for (int i = 1; i <= n; ++i) {
            d[i] = 0; inq[i] = 1; q.push(i);
        }

        while (!q.empty()) {
            int u = q.front(); q.pop(); inq[u] = 0;
            for (int i = 0; i < G[u].size(); ++i) {
                Edge e = edges[G[u][i]];
                //printf("%d %d %.2f\n", e.u, e.v, e.w);
                if (d[e.v] > d[e.u] + e.w) {
                    d[e.v] = d[e.u] + e.w;
                    if (!inq[e.v]) {
                        q.push(e.v); inq[e.v] = 1;
                        if (++cnt[e.v] > n) return true;
                    }
                }
            }
        }
        return false;
    }
};

bool test(Bellman solver, double val) {
    for (int i = 0; i < solver.edges.size(); ++i) solver.edges[i].w -= val;
    if (solver.negativeCycle()) return true;
    return false;
}

int main() {
    int T, n, m;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        printf("Case #%d: ", kase);
        Bellman solver;
        scanf("%d%d", &n, &m);
        solver.init(n);
        double l = 0, r = -1;
        while (m--) {
            int u, v;
            double w;
            scanf("%d %d %lf", &u, &v, &w);
            r = max(w, r);   //更新右边界
            solver.addEdge(u, v, w);
        }
        if (!test(solver, r + 1)) puts("No cycle found.");
        else {
            while (r - l > 1e-3) {
                double mid = (r + l) / 2;
                if (test(solver, mid)) r = mid;
                else l = mid;
            }
            printf("%.2f\n", l);
        }
    }
    return 0;
}
