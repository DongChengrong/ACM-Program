 #include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define N 110
#define INF 1000000000

typedef long long ll;

struct Edge {
    int u, v;
    ll c, f;
    bool operator < (const Edge &uu) const {
        if (u != uu.u) return u < uu.u;
        return v < uu.v;
    }
};

ll c;
int m, n;
int s, t;
int d[N], vis[N], cur[N];
vector<Edge> edges;
vector<int> G[N];

void init(int n) {
    s = 1, t = n;
    edges.clear();
    for (int i = 0; i <= n; ++i) G[i].clear();
    memset(cur, 0, sizeof(cur));
}

void addEdge(int u, int v, ll c) {
    edges.push_back((Edge){u, v, c, 0});
    edges.push_back((Edge){v, u, 0, 0});
    int m = edges.size();
    G[u].push_back(m - 2);
    G[v].push_back(m - 1);
}

int bfs() {
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(s);
    d[s] = 0; vis[s] = 1;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < G[x].size(); ++i) {
            Edge e = edges[G[x][i]];
            if (!vis[e.v] && e.c > e.f) {
                d[e.v] = d[e.u] + 1;
                vis[e.v] = 1;
                q.push(e.v);
            }
        }
    }
    return vis[t];
}

ll dfs(int u, ll a) {
    if (u == t || a == 0) return a;
    ll flow = 0, f;
    for (int &i = cur[u]; i < G[u].size(); ++i) {
        Edge &e = edges[G[u][i]];
        if (d[e.v] == d[e.u] + 1 && (f = dfs(e.v, min(a, e.c - e.f))) > 0) {
            a -= f; flow += f; e.f += f; edges[G[u][i] ^ 1].f -= f;
            if (a == 0) break;
        }
    }
    return flow;
}

vector<int> min_cut() {
    vector<int> res;
    for (int i = 0; i < edges.size(); ++i) {
        Edge e = edges[i];
        if (vis[e.u] && !vis[e.v] && e.c > 0) res.push_back(i);
    }
    return res;
}

void reduce() {
    for (int i = 0; i < edges.size(); ++i) edges[i].c -= edges[i].f;
}

void _clear() {
    for (int i = 0; i < edges.size(); ++i) edges[i].f = 0;
}

ll maxFlow() {
    ll flow = 0;
    while (bfs()) {
        memset(cur, 0, sizeof(cur));
        flow += dfs(s, INF);
        if (flow >= c) break;
    }
    return flow;
}

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int T = 0;
    while (scanf("%d%d%lld", &n, &m, &c) != EOF && n) {
        init(n);
        for (int i = 0; i < m; ++i) {
            int u, v; ll c;
            scanf("%d%d%lld", &u, &v, &c);
            addEdge(u, v, c);
        }
        m = edges.size();
        ll flow = maxFlow();
        printf("Case %d:", ++T);
        if (flow >= c) puts(" possible");
        else {
            vector<Edge> res;
            vector<int> cuts = min_cut();
            reduce();
            for (int i = 0; i < cuts.size(); ++i) {
                edges[cuts[i]].c = c; _clear();
                if (flow + maxFlow() >= c) res.push_back(edges[cuts[i]]);
                edges[cuts[i]].c = 0;
            }
            if (res.empty()) puts(" not possible");
            else {
                sort(res.begin(), res.end());
                printf(" possible option:");
                for (int i = 0; i < res.size(); ++i) {
                    if (i) printf(",");
                    printf("(%d,%d)", res[i].u, res[i].v);
                }
                puts("");
            }
        }
    }
    return 0;
}
