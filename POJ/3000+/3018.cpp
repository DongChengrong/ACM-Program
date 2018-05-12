#include<stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

#define N 110000

int vis[N], pa[N], d[N], used[N];
vector<int> vec[N];

void init(int n) {
    for (int i = 0; i <= n; ++i) pa[i] = i;
    memset(vis, 0, sizeof(vis));
    memset(d, 0, sizeof(d));
    memset(used, 0, sizeof(used));
    for (int i = 0; i <= n; ++i) vec[i].clear();
    for (int i = 0; i <= n; ++i) vec[i].push_back(i);
}

int findset(int x) {
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

int main() {
    int n, m;
    while (scanf("%d%d",&n,&m) == 2) {
        init(n);

        while (m--) {
            int u, v;
            scanf("%d%d",&u, &v);
            d[u]++; d[v]++;
            used[u] = used[v] = 1;
            int x = findset(u);
            int y = findset(v);
            if (x != y) {  //union
                pa[x] = y;
                for (int i = 0; i < vec[x].size(); ++i) {
                    vec[y].push_back(vec[x][i]);
                }
            }
        }

        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (!used[i]) continue;  //如果没有边则忽略它
            int x = findset(i);
            if (!vis[x]) {
                int v = 0;
                for (int j = 0; j < vec[x].size(); ++j) {
                    int deg = d[vec[x][j]];
                    if (deg & 1) v++;
                }
                cnt += (v == 0 ? 1 : v / 2);
                vis[x] = 1;
            }
        }

        printf("%d\n",cnt);
    }
    return 0;
}
