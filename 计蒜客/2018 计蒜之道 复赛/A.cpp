#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 11000
#define Mod 10
#define _for(i, a, b) for (int i = (a); i < (b); ++i)

typedef long long ll;

struct Node {
    int a, b;
    bool operator < (Node aa) {
        return (aa.a != a && a < aa.a) || (aa.a == a && b > aa.b);
    }
}a[N];

int main() {
    int T, n, x;
    scanf("%d", &T);
    while (T--) {
        long long res;
        scanf("%d%d", &n, &x); res = (ll)x;
        _for (i, 0, n) scanf("%d", &a[i].a);
        _for (i, 0, n) scanf("%d", &a[i].b);
        sort(a, a + n);
        _for (i, 0, n) res = (res * a[i].a + a[i].b) % Mod;
        printf("%lld\n", res % Mod);
    }
    return 0;
}
