#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f
#define N (int)(1e5 + 100)

int n;
int a[N], b[N];

int lis() {
    memset(b, INF, sizeof(b));
    for (int i = 0; i < n; ++i) {
        int p = lower_bound(b, b + n, a[i]) - b;
        b[p] = a[i];
    }
    return lower_bound(b, b + n + 10, INF) - b;
}

int LIS() {
    memset(b, INF, sizeof(b));
    for (int i = 0; i < n; ++i) {
        int p = upper_bound(b, b + n + 10, a[i]) - b;
        b[p] = a[i];
    }
    return lower_bound(b, b + n + 10, INF) - b;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        if (LIS() >= n - 1) { puts("YES"); continue; }
        reverse(a, a + n);
        if (LIS() >= n - 1) { puts("YES"); continue; }
        else puts("NO");
    }
    return 0;
}
