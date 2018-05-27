#include <stdio.h>
#include <string.h>

#define N 110000

typedef long long ll;

ll a[N], pre[N];

int main() {
    int n;
    while (scanf("%d",&n) == 1) {
        ll res = 0;
        memset(pre, 0, sizeof(pre));
        for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
        pre[0] = a[0];
        for (int i = 1; i < n; ++i) pre[i] = pre[i - 1] + a[i];
        for (int i = n - 1; i >= 1; i--) res += pre[i - 1] * a[i];
        printf("%lld\n",res);
    }
    return 0;
}
