#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

#define N 1100

double x[N], y[N];
double dp[N][N];

double dis(int i, int j) {
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) );
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) scanf("%lf%lf", &x[i], &y[i]);
        for (int i = 1; i < n - 1; ++i) dp[n - 1][i] = dis(n - 1, n) + dis(n, i);
        for (int i = n - 2; i >= 2; --i) {
            for (int j = 1; j < i; ++j) {
                dp[i][j] = min(dp[i + 1][j] + dis(i + 1, i), dp[i + 1][i] + dis(i + 1, j));
            }
        }
        printf("%.2f\n", dp[2][1] + dis(1, 2));
    }
    return 0;
}
