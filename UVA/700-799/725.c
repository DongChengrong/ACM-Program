#include <stdio.h>
#include <string.h>

#define N 15

int vis[N];

int check(int x) {
    int i;
    for (i = 0; i < 5; ++i) {
        int tmp = x % 10; x /= 10;
        if (vis[tmp]) return 0;
        vis[tmp] = 1;
    }
    return 1;
}

int main() {
    int n, flag = 0;
    while (scanf("%d", &n) != EOF && n) {
        if (flag) puts("");
        else flag = 1;

        int i, mark = 0;
        for (i = 1234; i <= 98765; ++i) {
            memset(vis, 0, sizeof(vis));
            if (!check(i)) continue;
            if (i * n < 100000) {
                if (!check(i * n)) continue;
                mark = 1; printf("%d /%s%d = %d\n", i * n, i < 10000 ? " 0" : " ", i, n);
            }
        }
        if (!mark) printf("There are no solutions for %d.\n", n);
    }
    return 0;
}
