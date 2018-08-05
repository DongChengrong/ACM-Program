//菲波那切数列 + 基本数学推理
#include <stdio.h>

#define N 25

typedef long long ll;

ll a, n, m, x;
ll f[N];

void init() {
    f[0] = 0;
    f[1] = f[2] = 1;
    for (int i = 3; i < N; ++i) f[i] = f[i - 1] + f[i - 2];
}

int main() {
    init();
    while (scanf("%lld%lld%lld%lld", &a, &n, &m, &x) != EOF) {
        if (x == 1 || x == 2) { printf("%lld\n", a); continue; }
        if (x == n) { printf("%lld\n", m); continue; }
        ll xx = (m - a - f[n - 3] * a) / (f[n - 2] - 1);
        printf("%lld\n", a + f[x - 2] * a + f[x - 1] * xx -  xx);
    }
    return 0;
}
