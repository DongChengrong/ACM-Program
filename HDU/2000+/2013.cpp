#include <stdio.h>
#include <math.h>

#define N 110

int dp[N];

int main() {
    int n;
    dp[0] = dp[1] = 1; dp[2] = 2; dp[3] = 3;
    for (int i = 4; i <= 55; ++i) dp[i] = dp[i - 3] + dp[i - 1];
    while (scanf("%d", &n) != EOF && n) {
        printf("%d\n", dp[n]);
    }
    return 0;
}
