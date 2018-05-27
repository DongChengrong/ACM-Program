#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 110000

typedef long long ll;

ll a[N];

int main() {
    int n;
    while (scanf("%d",&n) == 1) {
        int i;
        ll res = 0;
        for (i = 0; i < n; ++i) scanf("%d",&a[i]), res += a[i];

        sort(a, a + n);

        i = 0;
        while (res & 1 && i < n) {
            if (a[i] & 1) res -= a[i];
            i++;
        }
        if (res & 1) puts("0");
        printf("%lld\n", res);
    }
    return 0;
}

