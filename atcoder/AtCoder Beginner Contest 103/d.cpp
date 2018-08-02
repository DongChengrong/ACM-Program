#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 110000

struct Node {
    int l, r;
    bool operator < (Node u) {
        return r < u.r;
    }
}a[N];

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        int res = 0, l, r;
        for (int i = 0; i < m; ++i) scanf("%d%d", &a[i].l, &a[i].r);
        sort(a, a + m);
        if (m > 0) res = 1;
        l = a[0].l; r = a[0].r;
        int i = 1;
        while (i < m) {
            if (a[i].r < r || a[i].l >= r) {
                l = a[i].l; r = a[i].r;
                res++;
            }
            ++i;
        }
        printf("%d\n", res);
    }
    return 0;
}
