#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 120000

typedef long long ll;

int n;
ll c[N];
char cmd[15];

void add(int x, ll d) {
    while (x <= n) {
        c[x] += d;
        x += x & (-x);
    }
}

ll sum(int x) {
    ll ans = 0;
    while (x > 0) {
        ans += c[x];
        x -= x & (-x);
    }
    return ans;
}

int main() {
    int T; scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        printf("Case %d:\n", kase);
        scanf("%d", &n);
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x); add(i, x);
        }
        while (scanf("%s", cmd) != EOF) {
            if (cmd[0] == 'E') break;
            int u, v; scanf("%d%d", &u, &v);
            if (cmd[0] == 'A') add(u, (ll)v);
            if (cmd[0] == 'S') add(u, -v);
            if (cmd[0] == 'Q') printf("%lld\n", sum(v) - sum(u - 1));
        }
    }
    return 0;
}
