#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>

using namespace std;

#define N 1200000

typedef long long ll;

ll n, m;
ll a[N], l[N], r[N];

int main() {
    while (scanf("%I64d%I64d", &n, &m) != EOF) {
        set<ll> set1;
        memset(l, 0, sizeof(l)); memset(r, 0, sizeof(r));
        l[m + 1] = n + 1;
        for (int i = 1; i <= n; ++i) {
            scanf("%I64d", &a[i]);
            r[a[i] ] = i;
            set1.insert(a[i]);
            if (!l[a[i] ]) l[a[i]] = (ll)i;
        }
        vector<ll> tmp; for (int it : set1) tmp.push_back(it);
        for (int i = 1; i <= m; ++i) if (!r[i]) r[i] = r[i - 1];
        for (int i = m; i >= 1; --i) if (!l[i]) l[i] = l[i + 1];
        int x = -1, y = -1;
        for (int i = 1; i < tmp.size(); ++i) if (r[tmp[i - 1]] > l[tmp[i] ]) { x = tmp[i]; break; }
        for (int i = tmp.size() - 2; i >= 0; --i) if (r[tmp[i]] > l[tmp[i + 1]]) { y = tmp[i]; break; }
        if (x == -1) printf("%I64d\n", m * (m + 1) / 2);
        else {
            ll ans = 0;
            for (int i = m; i >= y; --i) {
                while (r[x - 1] > l[i + 1]) --x;
                ans += (ll)x;
            }
            printf("%I64d\n", ans);
        }
    }
    return 0;
}
/*
3 3
3 1 3
*/