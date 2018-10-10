#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 0x3f3f3f3f
#define N 150

struct Edge {
    int from, to, cap, flow;
};

struct Dinic {
    int n, m, s, t;
    int vis[N], d[N];
    vector <Edge> edges;
    vector<int> G[N];

    void clearAll(int n) {
        edges.clear();
        for (int i = 0; i <= n; ++i) G[i].clear();
    }

    void clearFlow(int n) {
        for (int i = 0; i < m; ++i) edges[i].flow = 0;
    }

    void addEdge(int u, int v, int cap) {
        edges.push_back((Edge){u, v, cap, 0});
        edges.push_back((Edge){v, u, 0, -cap});
        m = edges.size();
        G[u].push_back(m - 2);
        G[v].push_back(m - 1);
    }

    int maxFlow(int s, int t) {
        this->s = s; this->t = t;
    }


};

int main() {
    return 0;
}
