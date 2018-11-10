#include <stdio.h>
#include <math.h>

#define pi 3.1415926

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        double a, b, d;
        scanf("%lf%lf%lf", &a, &b, &d);
        double R = d / 2;
        double sa = pi * R * R;
        double l = sqrt(2 * R * R);
        double r = l / 2, sb = pi * r * r;
        double sabc = R * R / 2;
        double sshan = sa / 4;
        double shua = sb / 2 - sabc;
        double res = sb - sshan - shua;
        printf("%.6f\n", 4 * res);
    }
    return 0;
}
