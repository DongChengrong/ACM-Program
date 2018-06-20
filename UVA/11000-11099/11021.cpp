#include <stdio.h>

#define N 1100
#define _for(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

int n, k, m;
double f[N], a[N];

double qpow(double a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;

    double ans = qpow(a, b / 2);
    ans = ans * ans;
    if (b & 1) ans = ans * a;
    return ans;
}

int main() {
    int T;
    scanf("%d",&T);
    for (int kase = 1; kase <= T; ++kase) {
        scanf("%d%d%d", &n, &k, &m);
        _for (i, 0, n) scanf("%lf",&a[i]);
        f[0] = 0; f[1] = a[0];
        rep (i, 2, m) {
            f[i] = 0;
            _for (j, 0, n) {
                f[i] += a[j] * qpow(f[i - 1], j);
            }
        }
        printf("Case #%d: %.7f\n", kase, qpow(f[m],k));
    }
    return 0;
}
