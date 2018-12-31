#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef long long ll;

int main() {
    ll a, b;
    while (scanf("%lld%lld", &a, &b) != EOF) {
        ll c = b - a;
        if (c < 0) c = -1 * c;
        printf("%lld\n", c);
    }
    return 0;
}
