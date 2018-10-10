#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 550

int a[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, t1 = 0, t2 = 0; scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 3; i <= n; ++i) t1 += a[i] - a[i - 1] - 1;
        for (int i = 2; i < n; ++i) t2 += a[i] - a[i - 1] - 1;
        printf("%d\n", max(t1, t2));
    }
    return 0;
}
