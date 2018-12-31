#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define N 110000

int a[N];
int d[N][50];

int rmq(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1) ++k;
    return max(d[l][k], d[r - (1 << k) + 1][k]);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) d[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
        }
    }
    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
        int l = rmq(0, i);
        int r = rmq(i + 1, n - 1);
        //printf("%d %d\n", l, r);
        res = max(res, abs(l - r));
    }
    printf("%d\n", res);
    return 0;
}
