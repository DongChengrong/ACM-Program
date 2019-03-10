//ÌâÄ¿Á´½Ó£ºhttp://118.190.20.162/view.page?gpid=T81
#include <stdio.h>

typedef long long ll;

int main() {
    int n;
    ll k, t, res = 0;
    ll r, y, g;
    ll tot, time = 0;
    scanf("%lld%lld%lld", &r, &y, &g);
    scanf("%d", &n);
    tot = r + y + g;
    for (int i = 0; i < n; ++i) {
        ll tmp;
        scanf("%lld%lld", &k, &t);
        time = time % tot;
        if (k == 0) { res += t, time += t; continue; }
        if (k == 1) tmp = (t - time + tot) % tot;
        if (k == 2) tmp = (t + r - time + tot) % tot;
        if (k == 3) tmp = (t + r + y - time + tot) % tot;
        //printf("%lld %lld\n", tmp, res);
        if (tmp < r + y && tmp >= r) time += tmp, res += tmp;
        if (tmp < r) time += tmp, res += tmp;
        if (tmp >= r + y) continue;
    }
    printf("%lld\n", res);
    return 0;
}
