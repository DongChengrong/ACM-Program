#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 220000

typedef long long ll;

ll a[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n * 2; ++i) scanf("%I64d", &a[i]);
        sort(a, a + 2 * n);
        ll s1 = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
        ll l1 = (a[2 * n - 1] - a[0]);
        ll l2 = a[n] - a[1];
        for (int i = 2; i < n; ++i) {
            l2 = min(l2, a[i + n - 1] - a[i]);
        }
        printf("%I64d\n", min(l2 * l1, s1));
    }
    return 0;
}
