#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 1100

typedef long long ll;

ll n, m;
ll a[N];

int main() {
    while (scanf("%lld%lld", &n, &m) != EOF) {
        ll sum = 0;
        for (ll i = 0; i < n; ++i) scanf("%lld", &a[i]);
        sort(a, a + n);
        for (ll i = 0; i < n; ++i) {
            if (sum + 1 >= a[i]) sum += a[i];
            else break;
        }
        if (sum < m) puts("NO");
        else puts("YES");
    }
    return 0;
}
