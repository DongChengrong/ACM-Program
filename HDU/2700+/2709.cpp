#include <stdio.h>

#define N 1100000
#define Mod 1000000000

typedef long long ll;

int a[1100];
ll dp[N];

void init() {
    int n = 0;
    int MAX = 1000000;
    a[n++] = 1;
    while (a[n - 1] * 2 <= MAX) {
        a[n] = a[n - 1] * 2;
        n++;
    }

    //for(int i = 0; i < n; ++i) printf("%d\n",a[i]);

    for (int i = 0; i <= MAX; ++i) dp[i] = 1;
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i <= MAX; ++i) {
            if (i >= a[j]) dp[i] = (dp[i] + dp[i - a[j]]) % Mod;
        }
    }
}

int main() {
    init();
    int n;
    while (scanf("%d",&n) == 1) {
        printf("%lld\n",dp[n] % Mod);
    }
    return 0;
}
