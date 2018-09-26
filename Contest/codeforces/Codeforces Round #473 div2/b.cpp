/*
*题目链接：http://codeforces.com/contest/959/problem/B
*分析：每个集合取最小值，使用带权并查集
**/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define N 110000

typedef long long ll;

unordered_map<string, int> ma;   //从字符串映射到下标
ll a[N];
int pa[N];

int findset(int x) {
    return x == pa[x] ? pa[x] : pa[x] = findset(pa[x]);
}

void init(int n) {
    ma.clear();
    for (int i = 0; i <= n; ++i) {
        pa[i] = i;
    }
    char s[110];
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s);
        ma[s] = i;
    }
}

int main() {
    int n, k, m;
    while (scanf("%d%d%d", &n, &k, &m) != EOF) {
        ll res = 0;
        init(n);
        for (int i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
        while (k--) {
            int num, u, v;
            scanf("%d", &num);
            scanf("%d", &u); u = findset(u);
            for (int j = 1; j <= num - 1; ++j) {
                scanf("%d", &v); v = findset(v);
                if (u != v) {
                    pa[v] = u; a[u] = a[v] = min(a[u], a[v]);
                }
            }
        }
        for (int i = 1; i <= m; ++i) {
            char tmp[100];
            scanf("%s", tmp);
            int id = ma[tmp];
            id = findset(id);
            res += a[id];
        }
        printf("%I64d\n", res);
    }
    return 0;
}
