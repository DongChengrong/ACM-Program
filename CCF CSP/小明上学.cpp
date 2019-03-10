//ÌâÄ¿Á´½Ó£ºhttp://118.190.20.162/view.page?gpid=T80
#include <stdio.h>

typedef long long ll;

int r, y, g;
int t, k, n;

int main() {
    ll res = 0;
    scanf("%d%d%d", &r, &y, &g);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &k, &t);
        if (k == 0) res += t;
        if (k == 3) continue;
        if (k == 2) res += t + r;
        if (k == 1) res += t;
    }
    printf("%lld\n", res);
    return 0;
}
