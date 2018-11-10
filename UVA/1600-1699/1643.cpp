#include <stdio.h>
#include <math.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n) {
        int i;
        double s1 = 0, S = 0, l = 0;
        double p, a, b, c = 0;
        double x, y, k1, k2;
        scanf("%lf%lf", &x, &y); k1 = y / x;
        scanf("%lf%lf", &x, &y); k2 = y / x;
        for (i = 0; i < n; ++i) {
            scanf("%lf", &x);
            l = l + x; s1 = s1 + (x * x * 0.5);
        }
        c = sqrt(2 * l * l);
        x = (l + k2 * l) / (k1 - k2);
        y = k1 * x; a = sqrt(x * x + y * y);
        x = l + x; y = k2 * x; b = sqrt(x * x + y * y);
        p = 0.5 * (a + b + c);
        S = p * (p - a) * (p - b) * (p - c);
        S = sqrt(S) - s1;
        printf("%.3f\n", S);
    }
    return 0;
}
