#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

#define N 110
#define M 550
#define INF 0x3f3f3f3f
#define _for(i,a,b) for (int i = (a); i < (b); ++i)

typedef long long ll;

int n, m;
ll a[N], p[N], flow[N][N], G[N][N];
ll x[M], y[M];

void maxFlow(ll s, ll t) {
    memset(flow, 0, sizeof(flow));
    while (1) {
        memset(a, 0, sizeof(a));
        a[s] = INF;
        queue<ll> q;
        q.push(s);
        while (!q.empty()) {
            ll u = q.front(); q.pop();
            for (int i = 1; i <= n; ++i) {
                if (!a[i] && (flow[u][i] < G[u][i])) {
                    p[i] = u; a[i] = min(a[u], G[u][i] - flow[u][i]);
                    q.push(i);
                }
            }
            if (a[t]) break;
        }
        if (!a[t]) break;

        for (int i = t; i != s; i = p[i]) {
            flow[p[i]][i] += a[t];
            flow[i][p[i]] -= a[t];
        }

    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    while (scanf("%d%d", &n, &m) != EOF && n) {
        memset(G, 0, sizeof(G));
        _for (i, 0, m) {
            ll c;
            scanf("%lld%lld%lld", &x[i], &y[i], &c);
            G[x[i]][y[i]] = G[y[i]][x[i]] = c;
        }
        maxFlow(1,2);
        _for (i, 0, m) {
            if ((!a[x[i]] && a[y[i]]) || (a[x[i]] && !a[y[i]]) ) {
                printf("%lld %lld\n", x[i], y[i]);
            }
        }
        puts("");
    }
    return 0;
}
