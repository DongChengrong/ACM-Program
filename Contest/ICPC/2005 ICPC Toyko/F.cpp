#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 110
#define M 11000
#define INF 111111111

double b, r, v, e, f;
double dp[N], d[M];
int a[N];

double dis(double x) {
    if (x >= r) return 1.0 / (v - e * (x - r));
    return 1.0 / (v - f * (r - x));
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n) {
        a[0] = 0.0; for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        scanf("%lf%lf%lf%lf%lf", &b, &r, &v, &e, &f);
        for (int i = 1; i <= a[n]; ++i) {
            d[i] = d[i - 1] + dis(i - 1);
        }
        for (int i = 1; i <= n; ++i) {
            double res = d[a[i]];
            for (int j = 1; j < i; ++j) {
                res = min(res, dp[j] + b + d[a[i] - a[j]]);
            }
            dp[i] = res;
        }
        printf("%.4f\n", dp[n]);
    }
    return 0;
}
