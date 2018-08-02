#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 11000
#define INF 0x3f3f3f3f

struct Edge {
    int from, to, cap, flow;
    Edge() {}
    Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f){}
};

struct edmondsKarp {

    int n, m;
    vector<Edge> edges;
    vector<int> G[N];
    int a[N], p[N];

    void init(int n) {
        this->n = n;
        for (int i = 0; i < n; ++i) G[i].clear();
        edges.clear();
    }

    void addEdge(int u, int v, int c) {
        edges.push_back(Edge(u, v, c, 0));
        edges.push_back(Edge(v, u, 0, 0));
        int m = edges.size();
        G[u].push_back(m - 2);
        G[v].push_back(m - 1);
    }

    int maxFlow(int s, int t) {
        int flow = 0;
        for ( ; ; ) {
            memset(a, 0, sizeof(a));
            a[s] = INF;
            queue<int> q;
            q.push(s);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int i = 0; i < G[u].size(); ++i) {
                    Edge &e = edges[G[u][i]];
                    if (!a[e.to] && e.cap > e.flow) {
                        p[e.to] = G[u][i];
                        a[e.to] = min(a[u], e.cap - e.flow);
                    }
                }
                if (a[t]) break;
            }
            if (!a[t]) break;

            for (int u = t; u != s; u = edges[p[u]].from) {
                edges[p[u]].flow += a[t];
                edges[p[u]^1].flow -= a[t];
            }

            flow += a[t];
        }
        return flow;
    }

};

int main() {
    edmondsKarp edm;
    return 0;
}
