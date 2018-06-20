#include <stdio.h>

#define N 55

typedef long long ll;

int n;
ll dp[N];

void init() {
    dp[2] = 3;
    dp[0] = dp[1] = dp[3] = 0;
    for (int i = 4; i <= 30; ++i) dp[i] = dp[i - 2] * 3 + dp[i - 4] * 2;
}

int main() {
    init();
    while (scanf("%d",&n) == 1 && n != -1) {
        printf("%lld\n", dp[n]);
    }
    return 0;
}
