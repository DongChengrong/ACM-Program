#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define N 1100
#define INF 0x3f3f3f3f
#define _for(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)


struct Node {
    int d, u;
    Node() {}
    Node(int d, int u) {
        this->d = d;
        this->u = u;
    }
    bool operator < (const Node &a) const {
        return d > a.d;
    }
};

struct Edge {
    int v, w;
};

int n, m;
int d[N], vis[N];
vector<Edge> G[N];

void init(int n) {
    memset(vis, 0, sizeof(vis));
    memset(d, INF, sizeof(d));
    _for (i, 0, n + 10) G[i].clear();
}

void dijkstra() {
    d[1] = 0;
    priority_queue<Node> que;
    que.push(Node(0, 1));
    while (!que.empty()) {
        Node tmp = que.top(); que.pop();
        int u = tmp.u;
        //printf("%d\n",u);
        if (vis[u]) continue;
        vis[u] = 1;
        _for (i, 0, G[u].size()) {
            Edge e = G[u][i];
            int v = e.v;
            //printf("%d %d\n",u, v);
            if (d[v] > d[u] + e.w) {
                d[v] = d[u] + e.w;
                que.push(Node(d[v], v));
            }
        }
    }
}

int main() {
    while (scanf("%d%d",&m, &n) == 2) {
        init(n);
        while (m--) {
            int u, v, w;
            scanf("%d%d%d",&u, &v, &w);
            G[u].push_back((Edge){v, w});
            G[v].push_back((Edge){u, w});
        }
        dijkstra();
        //rep (i, 1, n) printf("%d\n",d[i]);
        printf("%d\n",d[n]);
    }
    return 0;
}
