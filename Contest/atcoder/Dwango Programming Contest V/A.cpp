#include <stdio.h>
#include <math.h>

#define N 1100
#define INF = 0x3f3f3f3f

double a[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &a[i]);
            sum += a[i];
        }
        sum /= n;
        int cnt = 0;
        double dif = fabs(sum - a[0]);
        for (int i = 1; i < n; ++i) {
            if (fabs(sum - a[i]) < dif) {
                dif = fabs(sum - a[i]);
                cnt = i;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
