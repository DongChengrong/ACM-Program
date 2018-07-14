/*
*   UVA 558
*  bellman ÅÐ¶Ï¸º»·
*/

#include <stdio.h>
#include <string.h>

#define N 2200
#define INF 0x3f3f3f3f

struct edge {
    int u, v, w;
};

int d[N];
int n, m;
edge e[N];

bool bellman() {
    memset(d, INF, sizeof(d));
    d[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (d[e[j].v] > d[e[j].u] + e[j].w) {
                if (i == n - 1) return true;
                d[e[j].v] = d[e[j].u] + e[j].w;
            }
        }
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i)
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        if (bellman()) puts("possible");
        else puts("not possible");
    }
    return 0;
}
