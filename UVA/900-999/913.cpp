#include <stdio.h>

typedef long long ll;

int main() {
    ll n, N;
    while (scanf("%lld", &N) != EOF) {
        n = (N + 1) / 2;
        if (n == 1) {
            puts("1"); continue;
        }

        printf("%lld\n", 3 * (2 * (n * n - 1) - 1));
    }
    return 0;
}
