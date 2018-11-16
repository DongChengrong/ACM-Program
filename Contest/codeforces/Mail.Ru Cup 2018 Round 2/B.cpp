#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 110000

typedef long long ll;

ll a[N];

int main() {
    ll n, m, l, res = 0;
    scanf("%I64d%I64d%I64d", &n, &m, &l);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d", &a[i]);
        if (a[i] > l && a[i - 1] <= l) ++res;
    }
    while (m--) {
        int cmd;
        ll u, v;
        scanf("%d", &cmd);
        if (!cmd) printf("%I64d\n", res);
        else {
            scanf("%I64d%I64d", &u, &v);
            if (a[u] > l) continue;
            else {
                a[u] += v;
                if (a[u] <= l) continue;
                if (a[u - 1] <= l && a[u + 1] <= l) ++res;
                if (a[u - 1] > l && a[u + 1] > l) --res;
            }
        }
    }
    return 0;
}
