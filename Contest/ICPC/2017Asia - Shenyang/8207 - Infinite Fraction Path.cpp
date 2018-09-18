//有点迭代深搜的感觉
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define N 2002000

ll n, T;
char s[N], res[N];

void Move(ll i, ll &p, ll &m) {
    p = (i * i + 1) % n;
    m = s[p] - '0';
}

int main() {
    scanf("%lld", &T);
    for (int kase = 1; kase <= T; ++kase) {
        scanf("%lld", &n);
        scanf("%s", &s);
        vector<ll> v[2];
        ll MAX = -1, u = 0, cnt = 0;
        for (ll i = 0; i < n; ++i) {
            if (s[i] - '0' > MAX) {
                MAX = s[i] - '0';
                v[u].clear(); v[u].push_back(i);
            } else if (MAX == s[i] - '0') v[u].push_back(i);
        }
        res[cnt] = '0' + MAX;

        MAX = -1;
        for (cnt = 1; cnt < n; ++cnt) {
            for (ll i = 0; i < v[u].size(); ++i) {
                ll p, m;
                Move(v[u][i], p, m);
                if (m > MAX) {
                    v[u ^ 1].clear();
                    v[u ^ 1].push_back(p);
                    MAX = m;
                } else if (MAX == m) v[u ^ 1].push_back(p);
            }
            u = u ^ 1;
            res[cnt] = '0' + MAX;
            MAX = -1;
        }
        res[cnt] = '\0';
        printf("Case #%d: ", kase);
        puts(res);
    }
    return 0;
}
