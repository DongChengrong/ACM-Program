#include <stdio.h>
#include <string.h>

#define N 260000  * 2

char s1[30], s2[30];
int pa[N], d[N];

int findset(int x) {
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

struct Trie {
    int sz, cnt;
    int ch[N][30];
    int val[N];

    void init() {
        sz = 1; cnt = 0;
        memset(val, 0, sizeof(val));
        memset(ch, 0, sizeof(ch));
    }

    int id(char c) { return c - 'a'; }

    int insert(char s[]) {
        int u = 0;
        int n = strlen(s);
        for (int i = 0; i < n; ++i) {
            int v = id(s[i]);
            if (!ch[u][v]) ch[u][v] = sz++;
            u = ch[u][v];
        }
        if (!val[u]) val[u] = ++cnt;
        return val[u];
    }
}ma;

void init() {
    ma.init();
    for (int i = 0; i < N; ++i) pa[i] = i;
    memset(d, 0, sizeof(d));
}

int main() {
    init();
    while (scanf("%s%s",s1,s2) == 2) {
        int u = ma.insert(s1);
        int v = ma.insert(s2);
        d[u]++; d[v]++;
        pa[findset(u)] = pa[findset(v)];
    }

    int ans = 0;
    int std = findset(1);

    for (int i = 1; i <=ma.cnt; ++i) {
        if (findset(i) != std) { puts("Impossible"); return 0; }
        if (ans > 2) break;
        if (d[i] & 1) ans++;
    }

    if (ans == 0 || ans == 2) puts("Possible");
    else puts("Impossible");

    return 0;
}
