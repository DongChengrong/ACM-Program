#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 11000

int a[N];

int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        int x;
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x); a[x]++;
        }
        x = -1;
        for (int i = 1; i <= 10000; ++i) {
            x = max(x, a[i] + a[i + 1]);
        }
        printf("%d\n", x);
    }
    return 0;
}
