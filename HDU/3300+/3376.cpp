//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=3376
//题目分类：最小费用最大流问题
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
int head[N];
int d[N], p[N], inq[N], a[N];
Edge edges[M];

void init() {
    m = 0;
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v, int cap, int cost) {
    edges[m] = (Edge){u, v, head[u], cap, 0, cost};
    head[u] = m++;
    edges[m] = (Edge){v, u, head[v], 0, 0, -cost};
    head[v] = m++;
}

int id(int i, int j) {
    return (i - 1) * n + j;
}

void build_graph() {  //1
    int base = n * n;
    addEdge(0, 1, 2, 0);
    addEdge(n * n * 2, n * n * 2 + 1, 2, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            scanf("%d", &x);
            if (id(i, j) == 1) c1 = x;
            if (id(i, j) == n * n) c2 = x;
            if (id(i,j) == 1 || id(i,j) == n * n) addEdge(id(i, j), id(i, j) + base, 2, x);
            else addEdge(id(i, j), id(i, j) + base, 1, x);
            if (i < n) addEdge(id(i, j) + n * n, id(i + 1, j), 1, 0);
            if (j < n) addEdge(id(i, j) + n * n, id(i, j + 1), 1, 0 );
        }
    }
}

bool bellman(int s, int t, int &flow, int &cost) {   //1
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

void maxFlow(int s, int t, int &flow, int &cost) {
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
