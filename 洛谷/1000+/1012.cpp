#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 11000

typedef long long ll;

int a[N];

int cmp(int a, int b) {
    int x[55], y[55], i = 0, j = 0;
    while (a) {
        x[i++] = a % 10; a /= 10;
    }
    while (b) {
        y[j++] = b % 10; b /= 10;
    }
    while (i > 0 && j > 0) {
        //printf("%d %d %d\n", k, x[k], y[k]);
        if (x[--i] != y[--j]) return x[i] > y[j];
    }
    if (!i) ++i;
    if (!j) ++j;
    return x[--i] > y[--j];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n, cmp);
    for (int i = 0; i < n; ++i) printf("%d", a[i]);
    return 0;
}
