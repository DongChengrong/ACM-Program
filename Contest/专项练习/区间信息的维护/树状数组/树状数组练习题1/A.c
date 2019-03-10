//这明明是差分标记好不好
#include <stdio.h>
#include <string.h>

#define N 110000

int c[N];

int main() {
    int n, i;
    while (scanf("%d", &n) != EOF && n) {
        int res = 0;
        memset(c, 0, sizeof(c));
        for (i = 0; i < n; ++i) {
            int l, r; scanf("%d%d", &l, &r);
            c[l]++; c[r + 1]--;
        }
        for (i = 1; i <= n; ++i) {
            res += c[i]; printf("%d%c", res, i == n ? '\n' : ' ');
        }
    }
    return 0;
}
