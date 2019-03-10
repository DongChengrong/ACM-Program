#include <stdio.h>
#include <math.h>
#include <set>

using namespace std;

typedef long long ll;

ll get(ll N, ll d) {
    ll n = N / d;
    ll a1 = 1;
    ll res = n * (2 * a1 + (n - 1) * d) / 2;
    return res;
}

int main() {
    ll n;
    while (scanf("%I64d", &n) != EOF) {
        ll m = sqrt(n);
        set<ll> s;
        for (ll d1 = 1; d1 <= m; ++d1) {
            if (n % d1 == 0) {
                ll d2 = n / d1;
                s.insert(get(n, d1));
                s.insert(get(n, d2));
            }
        }
        set<ll>::iterator it = s.begin();
        printf("%I64d", *it); ++it;
        while (it != s.end()) {
            printf(" %I64d", *it);
            ++it;
        }
        puts("");
    }
    return 0;
}
