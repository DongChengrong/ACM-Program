#include <stdio.h>
#include <math.h>

typedef long long ll;

int f(ll n) {
    int cnt = 0, i;
    for (i = 1; i < sqrt(n); ++i) {
        if (n % i == 0) {
            cnt += 2;
        }
    }
    if (sqrt(n) * sqrt(n) == n) cnt++;
    return cnt;
}

int main() {
    ll n;
    while (scanf("%lld",&n) == 1 && n) {
        int num = f(n);
        if (num % 2 == 1) puts("yes");
        else puts("no");
    }
    return 0;
}
