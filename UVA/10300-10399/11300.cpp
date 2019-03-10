#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define N 1000101

typedef long long ll;

ll a[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        ll m = 0;
        for (int i = 1; i <= n; ++i) {
            ll x; scanf("%lld", &x);
            a[i] = a[i - 1] + x;
            m += x;
        }

        m /= (ll)n;
        for (int i = 1; i < n; ++i) a[i] -= i * m;
        sort(a, a + n);
        ll mid = a[n / 2];
        ll res = 0;
        for (int i = 0; i < n; ++i) {
            res += abs(a[i] - mid);
        }
        printf("%lld\n", res);
    }
    return 0;
}
