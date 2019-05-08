#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 1100

typedef long long ll;

ll c[N];
vector<int> a[N];

ll sum(ll x) {
    ll res = 0;
    while (x > 0) {
        res += c[x];
        x -= x & (-x);
    }
    return res;
}

void add(ll x, int d) {
    while (x < N) {
        c[x] += d;
        x += x & (-x);
    }
}

int main() {
    int T; scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        int m, n, k;
        memset(c, 0, sizeof(c));
        scanf("%d%d%d", &m, &n, &k);
        for (int i = 0; i <= m; ++i) a[i].clear();
        for (int i = 0; i < k; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            a[u].push_back(v);
        }
        ll res = 0;
        for (int i = 1; i <= m; ++i) sort(a[i].begin(), a[i].end());
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < a[i].size(); ++j) {
                int v = a[i][j];
                add(v, 1);
                res += (ll)sum(n) - (ll)sum(v);
            }

        }
        printf("Test case %d: %lld\n", kase, res);
    }
    return 0;
}
/*
1
3 5 6
1 1
1 2
2 1
2 3
2 4
3 5
ÕýÈ·´ð°¸1
*/
