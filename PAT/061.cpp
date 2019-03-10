//ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805342720868352/problems/994805344776077312
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef long long ll;

#define N 330

struct Node {
    int u, v;

    void change() {
        u = abs(u);
        v = abs(v);
        if (u == 10000) u = 0;
        if (v == 10000) v = 0;
    }

    bool operator < (const Node &a) const {
        if (u != a.u) return u < a.u;
        return v < a.v;
    }

    bool operator == (const Node &a) const {
        return u == a.u && v == a.v;
    }

};

int n, m, cnt;
set<Node> s;
int M[N][N];
map<int, int> ma;
vector<int> G[N];

int get(char s[]) {
    int f = 0, res = 0;
    int sz = strlen(s);
    if (s[0] == '-') f = 1;
    for (int i = (f ? 1 : 0); i < sz; ++i) res = res * 10 + (s[i] - '0');
    if (res == 0) res = 10000;
    if (f) res = -res;
    return res;
}

int id(int x) {
    if (ma[x]) return ma[x];
    return (ma[x] = cnt++);
}

int same(int x, int y) {
    return (ll)x * (ll)y > 0;
}

int main() {
    cnt = 1;
    ma.clear();
    scanf("%d%d", &n, &m);
    memset(M, 0, sizeof(M));
    for (int i = 0; i < m; ++i) {
        char tmp1[15], tmp2[15];
        scanf("%s%s", tmp1, tmp2);
        int u = get(tmp1), v = get(tmp2);
        int x = id(u), y = id(v);
        G[x].push_back(v);
        G[y].push_back(u);
        M[x][y] = M[y][x] = 1;
    }
    int q; scanf("%d", &q);
    while (q--) {
        int u, v;
        s.clear();
        scanf("%d%d", &u, &v);
        int x = id(u), y = id(v);
        for (int i = 0; i < G[x].size(); ++i) {
            for (int j = 0; j < G[y].size(); ++j) {
                if (G[x][i] == G[y][j] || G[x][i] == v || G[y][j] == u || G[y][j] == v || G[x][i] == u) continue;
                if (!same(u, G[x][i]) || !same(v, G[y][j])) continue;
                if (M[id(G[x][i])][id(G[y][j])]) {
                    Node node = (Node){G[x][i], G[y][j] };
                    node.change();
                    s.insert(node);
                }
            }
        }
        printf("%d\n", s.size());
        if (!s.empty()) {
            for (Node u : s) {
                printf("%04d %04d\n", u.u, u.v);
            }
        }
    }
    return 0;
}
