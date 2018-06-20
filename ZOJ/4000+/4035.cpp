#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 110
#define _for(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

typedef long long ll;

int n, m;

struct Node {
    ll w;
    char s[N];
    bool operator < (const Node &a) const {
        if (w != a.w) return w > a.w;
        else return strcmp(s, a.s) < 0;
    }
}a[N];

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        ll res = 0;
        scanf("%d %d", &n, &m);
        _for (i, 0, n) scanf("%s %lld", a[i].s, &a[i].w);
        sort(a, a + n);
        rep (i, 1, m) res += a[i - 1].w * (m - i + 1);
        printf("%lld", res);
        _for (i, 0, m) printf(" %s",a[i].s);
        puts("");
    }
    return 0;
}
