#include <stdio.h>

int main() {
    double a, b, c;
    while (scanf("%lf%lf%lf", &a, &b, &c) != EOF) {
        printf("%.5f\n", (b * (b - 1) + a * b) / ((a + b) * (a + b - c - 1)));
    }
    return 0;
}
