#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 110

int a[N];

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        int n, q, p;
        scanf("%d%d%d", &n, &q, &p);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        sort(a, a + n);
        int res = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = sum + a[i];
            if (res >= q) break;
            if (sum <= p) ++res;
            else break;
        }
        printf("Case %d: %d\n", kase, res);
    }
    return 0;
}
