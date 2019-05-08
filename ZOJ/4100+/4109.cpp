#include <stdio.h>
#include <string.h>
#include <map>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define N 1000010
#define P pair<int, int>
#define mk(a, b) make_pair(a, b)

int pa[N], val[N], vis[N], _rank[N];
vector<int> G[N];
vector<int> ans;
//map<pair<int, int>, int > ma;

int findset(int x) {
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

void init(int n) {
    ans.clear();
    memset(vis, 0, sizeof(int) * (n + 3));
    memset(_rank, 0, sizeof(int) * (n + 3));
    for (int i = 1; i <= n; ++i) G[i].clear();
    for (int i = 1; i <= n; ++i) pa[i] = i, val[i] = i;
}

int main() {

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int T; scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        init(n); int cnt = n;
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            //P p = mk(u, v);
            //if (ma[p]) continue;
            //ma[p] = 1; ma[mk(v,u)] = 1;
            G[u].push_back(v);
            G[v].push_back(u);
            int x = findset(u);
            int y = findset(v);
            if (x != y) {
                cnt--;
                if (_rank[x] < _rank[y]) {
                    pa[x] = y;
                } else {
                    pa[y] = x;
                    if (_rank[x] == _rank[y]) _rank[x]++;
                }
            }
        }
        printf("%d\n", cnt);
        for (int i = 1; i <= n; ++i) {
            int fa = findset(i);
            if (fa == i) continue;
            if (i < val[fa]) {
                val[fa] = i;
            }
            val[i] = -1;
        }
        priority_queue<int, vector<int>, greater<int> > q;
        for (int i = 1; i <= n; ++i) if (val[i] != -1){ q.push(val[i]); vis[val[i]] = 1;}
        while (!q.empty()) {
            int u = q.top(); q.pop();
            ans.push_back(u);
            for (int i = 0; i < G[u].size(); ++i) {
                int v = G[u][i];
                if (!vis[v]) { q.push(v); vis[v] = 1; }
            }
        }
        int sz = ans.size();
        for (int i = 0; i < sz; ++i) printf("%d%c", ans[i], i == sz - 1 ? '\n' : ' ');
    }
    return 0;
}
