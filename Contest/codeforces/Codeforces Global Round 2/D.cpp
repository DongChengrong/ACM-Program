#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 110000

typedef long long ll;

ll a[N], s[N], pre[N];

int main() {
    int n, q; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%I64d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i < n - 1; ++i) s[i] = a[i + 1] - a[i];
    sort(s, s + n - 1);
    pre[0] = 0; for (int i = 0; i < n - 1; ++i) pre[i + 1] = pre[i] + s[i];
    scanf("%d", &q);
    while (q--) {
        ll l, r,w;
        scanf("%I64d%I64d", &l, &r);
        w = r - l + 1;
        int pos = lower_bound(s, s + n - 1, w) - s;
        ll res = w * (n - pos) + pre[pos];
        printf("%I64d", res);
        if (q) printf(" ");
    }
    puts("");
    return 0;
}
