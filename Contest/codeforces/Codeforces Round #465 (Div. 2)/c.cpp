#include <stdio.h>
#include <math.h>

double dis(double x1, double y1, double x2, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    double r, x1, x2, y1, y2;
    while (scanf("%lf %lf %lf %lf %lf", &r, &x1, &y1, &x2, &y2) != EOF) {
        if (x1 == x2 && y1 == y2) printf("%.6f %.6f %.6f\n", x1 + r / 2, y1, r / 2);
        else if (dis(x1, y1, x2, y2) >= r * r) printf("%.6f %.6f %.6f\n", x1, y1, r);
        else {
            double a = sqrt(dis(x1, y1, x2, y2));
            double b = 2 * r - (r - a);
            double c = x1 - x2;
            double d = c * b / a;
            double e = (y1 - y2) * b / a;
            printf("%.6f %.6f %.6f\n", x2 + d / 2, y2 + e / 2, b / 2);
        }
    }
    return 0;
}
