#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define N 220
#define INF 111111111111111ll

typedef long long ll;

struct Edge {
    ll u, v, c, f;
};

ll n, m, x;
ll d[N], cur[N];
vector<Edge> edges;
vector<int> G[N];

void addEdge(ll u, ll v, ll c) {
    edges.push_back((Edge){u, v, c, 0});
    edges.push_back((Edge){v, u, 0, 0});
    int sz = edges.size();
    G[u].push_back(sz - 2);
    G[v].push_back(sz - 1);
}

int bfs() {
    for (int i = 0; i <= n; ++i) d[i] = INF;
    queue<int> q; q.push(1); d[1] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); ++i) {
            Edge e = edges[G[u][i]];
            if (e.c > e.f && d[e.v] == INF) {
                d[e.v] = d[u] + 1;
                q.push(e.v);
            }
        }
    }
    return d[n] != INF;
}

ll dfs(ll u, ll a) {
    if (u == n || a == 0) return a;
    ll flow = 0, f;
    for (ll &i = cur[u]; i < G[u].size(); ++i) {
        Edge &e = edges[G[u][i]];
        if (d[e.v] == d[u] + 1 && (f = dfs(e.v, min(a, e.c - e.f)))) {
            e.f += f; a -= f; edges[G[u][i] ^ 1].f -= f; flow += f;
            if (!a) break;
        }
    }
    return flow;
}

ll maxFlow() {
    ll res = 0;
    while (bfs()) {
        memset(cur, 0, sizeof(cur));
        res += dfs(1, INF);
    }
    return res;
}

int main() {
    scanf("%lld%lld%lld", &n, &m, &x);
    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        addEdge(u, v, w);
    }
    ll d = maxFlow();
    if (d == 0) puts("Orz Ni Jinan Saint Cow!"); else printf("%lld %lld\n", d, (x + d - 1) / d);
    return 0;
}
