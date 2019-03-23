#include <stdio.h>

int main() {
    int n, m;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 3; i <= 6; ++i) {
            double x; scanf("%lf", &x);
            printf("G[%d][%d][%d] = %.3f;\n", n / 10, m / 10, i, x);
        }
    }
    return 0;
}
