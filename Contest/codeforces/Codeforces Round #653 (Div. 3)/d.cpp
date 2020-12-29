#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

#define N 220000

typedef long long ll;

map<ll, ll> ma;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ma.clear();
        ll n, k, max_num = -1;
        scanf("%I64d%I64d", &n, &k);
        for (int i = 0; i < n; ++i) {
            ll x; scanf("%I64d", &x); x = x % k;
            if (x == 0) continue;
            ma[x]++;
            if (max_num == -1) max_num = x;
            else {
                if (ma[x] > ma[max_num] || (ma[x] == ma[max_num] && x < max_num)) {
                    max_num = x;
                }
            }
        }
        if (max_num == -1) printf("0\n");
        else printf("%I64d\n", (ma[max_num] - 1) * k + (k - max_num) + 1);
    }
    return 0;
}
