#include <stdio.h>

#define max(a, b) ((a) > (b)) ? (a) : (b)

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        int n, res = -1; scanf("%d", &n);
        while (n--) {
            int x; scanf("%d", &x);
            res = max(x, res);
        }
        printf("Case %d: %d\n", kase, res);
    }
    return 0;
}
