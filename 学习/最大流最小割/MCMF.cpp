#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define N 5500
#define M 55000
#define INF 0x3f3f3f3f

typedef long long ll;

struct Edge {
    int from, to, cap, flow, cost;
};

int flow;
ll cost;
int n, m, s, t;
int a[N], p[N], inq[N], d[N];
vector<Edge> edges;
vector<int> G[N];

void addEdge(int u, int v, int cap, int cost) {
    edges.push_back((Edge){u, v, cap, 0, cost});
    edges.push_back((Edge){v, u, 0, 0, -cost});
    int m = edges.size();
    G[u].push_back(m - 2);
    G[v].push_back(m - 1);
}

bool bellman(int s, int t) {
    queue<int> q;
    memset(inq, 0, sizeof(inq));
    memset(a, 0, sizeof(a));
    memset(d, INF, sizeof(d));
    d[s] = 0; a[s] = INF; inq[s] = 1; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = 0;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge e = edges[G[u][i]];
            if (d[e.to] > d[u] + e.cost && e.cap > e.flow) {
                d[e.to] = d[u] + e.cost;
                p[e.to] = G[u][i];
                a[e.to] = min(e.cap - e.flow, a[e.from]);
                if (!inq[e.to]) {
                    inq[e.to] = 1;
                    q.push(e.to);
                }
            }
        }
    }
    if (!a[t]) return false;

    flow += a[t];
    cost += (ll)d[t] * a[t];
    for (int i = t; i != s; i = edges[p[i]].from) {
        edges[p[i] ].flow += a[t];
        edges[p[i] ^ 1].flow -= a[t];
    }

    return true;
}

void maxFlow(int s, int t) {
    flow = cost = 0;
    while (bellman(s, t));
}

void bulid() {

    for (int i = 0; i <= n; ++i) G[i].clear();
    edges.clear();

    int u, v, c, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d%d", &u, &v, &c, &w);
        addEdge(u, v, c, w);
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    bulid();
    maxFlow(s, t);
    printf("%d %lld\n", flow, cost);
    return 0;
}
