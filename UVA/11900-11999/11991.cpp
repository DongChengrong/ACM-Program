#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

#define N 1100000
#define _for(i,a,b) for (int i = (a); i < (b); ++i)

int vis[N];
map<int, int> ma[N];

void init() {
    memset(vis, 0, sizeof(vis));
    _for (i, 0, N) ma[i].clear();
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        init();
        _for (i, 0, n) {
            int x, p;
            scanf("%d", &x);
            p = ++vis[x];
            ma[p][x] = (i + 1);
        }
        _for (i, 0, m) {
            int k, v;
            scanf("%d%d", &k, &v);
            printf("%d\n", ma[k][v]);
        }
    }
    return 0;
}
