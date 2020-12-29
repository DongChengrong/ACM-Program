#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 1100000

int a[N];

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        while (m--) {
            int x; scanf("%d", &x);
            int pos = lower_bound(a, a + n, x) - a;
            if (a[pos] == x) printf("%d", pos + 1);
            else printf("-1");
            if (m) printf(" ");
        }
        puts("");
    }
    return 0;
}
