//ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805342720868352/problems
#include <stdio.h>
#include <string.h>

#define N 1100

double v1[N], v2[N];

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int x; double y;
        for (int i = 0; i <= 1000; ++i) v1[i] = v2[i] = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%lf", &x, &y);
            v1[x] += y;
        }
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%lf", &x, &y);
            v2[x] += y;
        }

        n = 0;
        for (int i = 1000; i >= 0; --i) {
            if (v1[i] != 0 || v2[i] != 0) {
                v1[i] += v2[i];
                if (v1[i] != 0) n++;
            }
        }

        printf("%d", n);
        for (int i = 1000; i >= 0; --i) {
            if (v1[i] != 0) printf(" %d %.1f", i, v1[i]);
        }
        puts("");
    }
    return 0;
}
