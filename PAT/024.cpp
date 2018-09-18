//ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define N 110

struct Node {
    int u, step;
};

int n, m;
int ans[N];
vector<int> G[N];

void init() {
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < N; ++i) G[i].clear();
}

int main() {
    while (scanf("%d%d",&n, &m) != EOF) {
        init();
        while (m--) {
            int u, v, tmp;
            scanf("%d%d", &u, &tmp);
            for (int i = 0; i < tmp; ++i) {
                scanf("%d", &v);
                G[u].push_back(v);
            }
        }
        int cnt = 0;
        queue<Node> q;
        q.push((Node){1, 0});
        while (!q.empty()) {
            Node u = q.front(); q.pop();
            if (!G[u.u].size()) ans[u.step]++;
            for (int i = 0; i < G[u.u].size(); ++i) {
                Node v = u; v.step++; v.u = G[u.u][i];
                q.push(v); cnt = max(cnt, v.step);
            }
        }
        for (int i = 0; i <= cnt; ++i) printf("%d%c", ans[i], i == cnt ? '\n' : ' ');
    }
    return 0;
}
