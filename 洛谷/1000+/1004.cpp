//题目链接：https://www.luogu.org/problem/P1004
//题目分类：最小费用最大流问题
//分析：详见hdu3376
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

#define INF 0x3f3f3f3f
#define N (610 * 610 * 3)
#define M (N * 2 + 10000)

struct Edge {
    int from, to, next, cap, flow, cost;
};

int n, m;
int c1, c2;
int head[N], vis[N];
int d[N], p[N], inq[N], a[N];
Edge edges[M];

void init() {
    m = 0;
    memset(vis, 0, sizeof(vis));
    memset(head, -1, sizeof(head));
}

//函数参数依次代表源节点、目的节点、容量、花费
void addEdge(int u, int v, int cap, int cost) {
    edges[m] = (Edge){u, v, head[u], cap, 0, cost};
    head[u] = m++;
    edges[m] = (Edge){v, u, head[v], 0, 0, -cost};
    head[v] = m++;
}

//对节点进行编号
int id(int i, int j) {
    return (i - 1) * n + j;
}

//建图
void build_graph() {
    int x, y, v;
    int base = n * n;
    addEdge(0, 1, 2, 0);
    addEdge(n * n * 2, n * n * 2 + 1, 2, 0);
    while (scanf("%d%d%d", &x, &y, &v) != EOF) {
        if (x == 0 && y == 0 && v == 0) break;
        if (id(x, y) == 1) c1 = v;
        if (id(x, y) == n * n) c2 = v;
        if (id(x,y) == 1 || id(x,y) == n * n) addEdge(id(x, y), id(x, y) + base, 2, v);
        else addEdge(id(x, y), id(x, y) + base, 1, v);
        if (x < n) addEdge(id(x, y) + n * n, id(x + 1, y), 1, 0);
        if (y < n) addEdge(id(x, y) + n * n, id(x, y + 1), 1, 0 );
        vis[id(x, y)] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x = 0;
            if (vis[id(i, j)]) continue;
            if (id(i, j) == 1) c1 = x;
            if (id(i, j) == n * n) c2 = x;
            if (id(i,j) == 1 || id(i,j) == n * n) addEdge(id(i, j), id(i, j) + base, 2, x);
            else addEdge(id(i, j), id(i, j) + base, 1, x);
            if (i < n) addEdge(id(i, j) + n * n, id(i + 1, j), 1, 0);
            if (j < n) addEdge(id(i, j) + n * n, id(i, j + 1), 1, 0 );
        }
    }
}

bool bellman(int s, int t, int &flow, int &cost) {
    queue<int> q;
    memset(inq, 0, sizeof(inq));
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n * n * 2 + 10; ++i) d[i] = -INF;
    d[s] = 0; inq[s] = 1; q.push(s); a[s] = INF;
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = 0;
        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            if (d[v] < d[u] + edges[i].cost && edges[i].cap > edges[i].flow) {
                d[v] = d[u] + edges[i].cost;
                a[v] = min(a[u], edges[i].cap - edges[i].flow);
                p[v] = i;
                if (!inq[v]) {
                    inq[v] = 1; q.push(v);
                }
            }
        }
    }
    if (a[t] == 0) return false;

    for (int i = t; i != s; i = edges[p[i]].from) {
        cost += edges[p[i]].cost * a[t];
        edges[p[i]].flow += a[t];
        edges[p[i] ^ 1].flow -= a[t];
    }
    flow += a[t];
    return true;
}

void maxFlow(int s, int t, int &flow, int &cost) {   //1
    flow = cost = 0;
    while (bellman(s, t, flow, cost));
}

int main() {
    while (scanf("%d", &n) != EOF) {
        int flow, cost;
        init();
        build_graph();
        maxFlow(0, 2 * n * n + 1, flow, cost);
        printf("%d\n", cost - c1 - c2);
    }
    return 0;
}
