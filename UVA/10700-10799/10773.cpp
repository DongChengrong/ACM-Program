#include <math.h>
#include <stdio.h>

int main() {
    int T, kase = 0;
    scanf("%d", &T);
    while (T--) {
        double d, u, v;
        scanf("%lf%lf%lf", &d, &v, &u);
        if (d == 0 || u == 0 || v == 0 || u <= v) printf("Case %d: can't determine\n", ++kase);
        else {
            double t1 = d / u;
            double t2 = d / (sqrt(u * u - v * v));
            printf("Case %d: %.3f\n", ++kase, t2 - t1);
        }
    }
    return 0;
}
