#include <stdio.h>
#include <algorithm>

using namespace std;

int a[110];

int main() {
    int T; scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        sort(a, a + n);
        printf("Case %d: %d\n", kase, a[n / 2]);
    }
    return 0;
}
