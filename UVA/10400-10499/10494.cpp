#include <stdio.h>

typedef long long ll;

int main() {
    ll a, b; char c;
    while (scanf("%lld %c %lld", &a, &c, &b)!= EOF) {
        if (c == '%') printf("%lld\n", a % b);
        else printf("%lld\n", a / b);
    }
    return 0;
}
