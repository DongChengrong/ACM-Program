//ÌâÄ¿Á´½Ó£ºhttp://118.190.20.162/view.page?gpid=T83
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 110000

struct Edge {
    int u, v, t;
    bool operator < (const Edge &u) const {
        return t < u.t;
    }
};

int pa[N];
int n, m, root;
Edge e[N];

int findset(int x) {
    return x == pa[x] ? x : pa[x] = findset(pa[x]);
}

int main() {
    for (int i = 0; i < N; ++i) pa[i] = i;
    scanf("%d%d%d", &n, &m, &root);
    int cnt = n;
    for (int i = 0; i < m; ++i) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].t);
    sort(e, e + m);
    int res = -100;
    for (int i = 0; i < m; ++i) {
        if (cnt == 1) break;
        int x = findset(e[i].u);
        int y = findset(e[i].v);
        if (x != y) {
            pa[x] = y;
            cnt--;
            res = max(res, e[i].t);
        }
    }
    printf("%d\n", res);
    return 0;
}
