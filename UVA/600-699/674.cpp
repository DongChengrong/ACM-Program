#include <stdio.h>
#include <string.h>

#define N 11000

typedef long long ll;

ll dp[N], a[] = {1, 5, 10, 25, 50};

void init() {
    int MAX = 8000;
    for (int i = 0; i <= MAX; ++i) dp[i] = 1;
    for (int i = 1; i < 5; ++i) {
        for (int j = 0; j <= MAX; ++j) {
            if (j >= a[i]) dp[j] += dp[j - a[i]];
        }
    }
}

int main() {
    int n;
    init();
    while (scanf("%d",&n) == 1) {
        //for (int i = 1; i <= 11; ++i) printf("%d %d\n",i, dp[i]);
        printf("%lld\n",dp[n]);
    }
    return 0;
}
