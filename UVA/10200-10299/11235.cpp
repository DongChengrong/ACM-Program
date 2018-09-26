#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 220000
#define M 32

int a[N], d[N], val[N][M];

void init(int n) {
    val[1][0] = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == 0 && d[i] != 1) d[i + 1][0] = 1;
        else if (a[i] == 0) d[i + 1][0] = 2;
    }
}

int main() {
    int n, q;
    while (scanf("%d%d", &n, &q) == 2 && n) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) d[i + 1] = a[i + 1] - a[i];
        init(n);
        while (q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", rmq(l, r));
        }
    }
    return 0;
}
