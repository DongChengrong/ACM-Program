#include <stdio.h>
#include <string.h>

#define N 1010000
#define M 11000

int n, m;
int a[N], b[M], next[M];

void getFail() {
    next[0] = next[1] = 0;
    for (int i = 1; i < m; ++i) {
        int j = next[i];
        while (j && b[j] != b[i]) j = next[j];
        next[i + 1] = (b[i] == b[j] ? j + 1 : 0);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
        getFail();
        //for (int i = 0; i < m; ++i) printf("%d ", next[i]);
        //puts("");
        int j = 0, i;
        for (i = 0; i < n; ++i) {
            while (j && a[i] != b[j]) j = next[j];
            //printf("%d %d\n", i, j);
            if (a[i] == b[j]) ++j;
            if (j == m) break;
        }
        if (j == m) printf("%d\n", i - m + 2);
        else puts("-1");
    }
    return 0;
}
