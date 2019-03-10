#include <stdio.h>
#include <math.h>

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        double n; scanf("%lf",  &n);
        double a = floor(n / 2);
        double b = floor((n - a) / 3 * 2);
        double c = n - a - b;
        int ans1 = ceil(a / 10);
        int ans2 = ceil(b / 10);
        int ans3 = ceil(c / 10);
        printf("%d\n", ans1 + ans2 + ans3);
    }
    return 0;
}
