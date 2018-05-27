#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        ll a, b, c, d, tmp;
        scanf("%lld%lld",&a,&b);
        tmp = a + b;
        c = d = tmp / 2;
        if (tmp & 1) d += 1;
        if (abs(c - d) == abs(a -  b)) puts("Ok");
        else printf("%lld %lld\n", c, d);
    }
    return 0;
}
