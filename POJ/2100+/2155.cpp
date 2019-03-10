#include <stdio.h>
#include <string.h>

#define N 1100

int n, t, T;
int c[N][N];

void add(int x, int y) {
    for (int i = x; i <= n; i += i & (-i)) {
        for (int j = y; j <= n; j += j & (-j)) {
            c[i][j] += 1;
        }
    }
}

int sum(int x, int y) {
    int res = 0;
    for (int i = x; i > 0; i -= i & (-i)) {
        for (int j = y; j > 0; j -= j & (-j)) {
            res += c[i][j];
        }
    }
    return res;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &t);
        memset(c, 0, sizeof(c));
        while (t--) {
            char cmd[15];
            scanf("%s", cmd);
            if (cmd[0] == 'Q') {
                int x, y;
                scanf("%d%d", &x, &y);
                printf("%d\n", sum(x, y) & 1);
            } else if (cmd[0] == 'C') {
                int x1, x2, y1, y2;
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                add(x1, y1); add(x1, y2 + 1);
                add(x2 + 1, y1); add(x2 + 1, y2 + 1);
            }
        }
        if (T) puts("");
    }
    return 0;
}
