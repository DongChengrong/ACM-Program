#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 110000
#define _for(i, a, b) for (int i = (a); i < (b); ++i)

typedef long long ll;

struct Node {
    ll val, val2, id;
    bool operator < (const Node &u) const {
        return (val + val2) > (u.val + u.val2);
    }
};

int vis[N];
Node a[N], b[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        memset(vis, 0, sizeof(vis));
        for (ll i = 0; i < n; ++i) {
            scanf("%lld%lld", &a[i].val, &b[i].val);
            a[i].id = b[i].id = i;
            a[i].val2 = b[i].val;
            b[i].val2 = a[i].val;
        }
        int cur = 0, cnt = 0, i = 0, j = 0;
        sort(a, a + n); sort(b, b + n);
        ll sum1 = 0, sum2 = 0;
        while (cnt < n) {
            while (i < n && vis[a[i].id]) i++;    //·Ö±ð¹éÎ»
            while (j < n && vis[b[j].id]) j++;
            if (!cur) {
                sum1 += a[i].val, vis[a[i].id] = 1;
                //else sum1 += b[j].val2, vis[b[j].id ] = 1;
            } else {
                sum2 += b[j].val, vis[b[j].id] = 1;
                //else sum2 += a[i].val2, vis[a[i].id] = 1;
            }
            cnt++;
            cur = cur ^ 1;
        }
        printf("%lld\n", sum1 - sum2);
    }
    return 0;
}
