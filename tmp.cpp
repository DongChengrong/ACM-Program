#include <stdio.h>
#include <math.h>

int main() {
    float k1, k2, a, b;
    scanf("%f%f%f%f", &k1, &a, &k2, &b);
    double res = (a * k1 - b * k2) / (a - b);
    printf("%.2f\n", fabs(res));
    return 0;
}
