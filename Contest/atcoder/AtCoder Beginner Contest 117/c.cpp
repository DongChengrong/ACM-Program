#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 110000
#define INF 0x3f3f3f3f
#define _for(i, a, b) for (int i = (a); i < (b); ++i)

typedef long long ll;

int a[N], dif[N];

int main() {
    int n, m;
    while (scanf("%d%d", &m, &n) != EOF) {
        int res = 0;
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        sort(a, a + n);
        for (int i = 0; i < n - 1; ++i) dif[i] = a[i + 1] - a[i];
        n = n - 1; m = m - 1;
        sort(dif, dif + n);
        for (int i = 0; i < n - m; ++i) res += dif[i];
        printf("%d\n", res);
    }
    return 0;
}
