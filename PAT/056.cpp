//ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805342720868352/problems/994805343979159552
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#define N 220

int G[N][N];

int in(int u, vector<int> vec) {
    int sz = vec.size();
    for (int i = 0; i < sz; ++i) if (u == vec[i]) return 1;
    return 0;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++i) G[i][i] = 1;
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u][v] = G[v][u] = 1;
    }
    int T; scanf("%d", &T);
    while (T--) {
        int tmp, flag = 1;
        vector<int> vec;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &tmp);
            vec.push_back(tmp);
        }

        int sz = vec.size();
        for (int i = 0; i < sz - 1; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                int u = vec[i], v = vec[j];
                if (!G[u][v]) {
                    flag = 0; break;
                }
            }
            if (!flag) break;
        }
        if (!flag) {
            puts("Not a Clique");
            continue;
        }

        for (int i = 1; i <= n; ++i) {
            if (in(i, vec)) continue;
            int mark = 1;
            for (int j = 0; j < sz; ++j) if (!G[i][vec[j]]) { mark = 0; break; }
            if (mark) { flag = 0; break; }
        }
        if (flag) puts("Yes");
        else puts("Not Maximal");
    }
    return 0;
}
