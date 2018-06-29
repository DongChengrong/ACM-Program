#include <stdio.h>
#include <math.h>

#define N 1100

int f[N];

void init() {
    for (int i = 1; i < N; ++i) {
        f[i] = 0;
        for (int j = 1; j <= sqrt(i); ++j) {
            if (i % j == 0) f[i] += j;
            if (i % j == 0 && i / j != j) f[i] += (i / j);
        }
    }
}

int main() {
    int n, kase = 1;
    init();
    while (scanf("%d", &n) == 1 && n) {
        int p;
        for (p = 1000; p >= 1; --p) if (f[p] == n) break;
        printf("Case %d: %d\n", kase++, p == 0 ? -1 : p);
    }
    return 0;
}
