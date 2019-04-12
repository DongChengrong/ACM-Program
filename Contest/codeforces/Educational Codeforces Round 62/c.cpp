#include <stdio.h>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;

#define N 330000
#define mk(a, b) make_pair(a, b)
#define P pair<ll, ll>

typedef long long ll;

int n, k;
pair<ll, ll> a[N];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%I64d%I64d", &a[i].second, &a[i].first);
    sort(a, a + n);
    set<P> s;
    ll res = 0, sum = 0;
    for (int i = n - 1; i >= 0; --i) {
        s.insert(mk(a[i].second, i));
        sum += a[i].second;
        while (s.size() > k) {
            auto it = s.begin();
            sum -= it->first;
            s.erase(it);
        }
        res = max(res, a[i].first * sum);
    }
    printf("%I64d\n", res);
    return 0;
}
