#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

#define N 220000

ll a[N];

ll dis(ll x, ll y) {

}

int main() {
    ll l, n;
    while (scanf("%lld%lld", &l, &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
        }
        sort(a, a + n);
        int dir = 0;
        ll sum = 0, cur = 0;
        int i = 0, j = n - 1;
        while (i <= j) {
            ll x = a[i] - cur;
            ll y = cur - a[j];
            if (x < 0) x += l;
            if (y < 0) y += l;
            if (x > y) {
                cur = a[i]; sum += x; ++i;
            } else if (x == y) {
                if (a[i + 2] - a[i + 1] > a[j - 1] - a[j - 2]) {
                    cur = a[i]; sum += x; ++i;
                } else if (a[i + 2] - a[i + 1] == a[j - 1] - a[j - 2]){
                    if (a[i + 1] - a[i] > a[j] - a[j - 1]) {
                        cur = a[i]; sum += x; ++i;
                    } else {
                        cur = a[j]; sum += y; --j;
                    }
                } else {
                    cur = a[j]; sum += y; --j;
                }
            } else {
                cur = a[j]; sum += y; --j;
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}
