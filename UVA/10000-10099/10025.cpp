/*
*打表找规律 最后可以发现最大可以表示的数据范围是f[i - 1] + i;
*而且当(i - 1)% 4 < 2时可以表示从1 到f[i]的所有奇数
*否则可以表示从0到f[i]的所有偶数
**/
#include <stdio.h>
#include <string.h>
#include <set>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef long long ll;

#define N 1200000
#define M 1000000000LL

void pre();

int m;
ll f[N];

void init() {
    f[1] = 1, m = 2;
    while (1) {
        f[m] = f[m - 1] + m; ++m;
        if (f[m - 1] > M) break;
    }
}

int main() {
    int T;
    init();
    scanf("%d", &T);
    while (T--) {
        ll n;
        scanf("%lld", &n); n = abs(n);
        int pos = lower_bound(f + 1, f + m, n) - f;
        int k = (pos - 1) % 4;
        if (n & 1) {
            if (k < 2) printf("%d\n", pos); else printf("%d\n", pos + (4 - k));
        } else {
            if (k < 2) printf("%d\n", pos + (2 - k)); else printf("%d\n", pos);
        }
        if (T) puts("");
    }
    return 0;
}

//打表找规律
void pre() {
    freopen("out.txt", "w", stdout);

    for (int i = 1; i <= 10; ++i) {
        set<int> s;
        for (int j = 0; j < (1 << i); ++j) {
            int ans = 0;
            for (int k = 0; k < i; ++k) {
                if ((1 << k) & j) ans += -(k + 1);
                else ans += (k + 1);
            }
            s.insert(ans);
        }
        printf("%d : ", i); for (int u : s) printf("%d ", u); puts("");
    }
}
