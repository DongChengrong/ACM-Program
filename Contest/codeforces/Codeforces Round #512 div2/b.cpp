#include <stdio.h>
#include <stdlib.h>

int read() {
    int tmp; scanf("%d", &tmp);
    return tmp;
}

int d, n;

int main() {
    while (scanf("%d%d", &n, &d) != EOF) {
        int m = read();
        while (m--) {
            int x = read(), y = read();
            int t1 = x + y, t2 = abs(x - y);
            if (t1 >= d && t1 <= 2 * n - d && t2 <= d) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
