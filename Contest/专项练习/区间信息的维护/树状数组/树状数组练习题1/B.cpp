#include <stdio.h>
#include <string.h>

#define N 1100

int n, m;
int c[N][N];

void add(int r, int x, int d) {
    while (x <= n) {
        c[r][x] += d;
        x += x & (-x);
    }
}

int sum(int r, int x) {
    int res = 0;
    while (x > 0) {
        res += c[r][x];
        x -= x & (-x);
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) memset(c[i], 0, sizeof(c[i]));
        while (m--) {
            char cmd[5];
            int x1, x2, y1, y2;
            scanf("%s", cmd);
            if (cmd[0] == 'C') {
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                for (int r = y1; r <= y2; ++r) {
                    add(r, x1, 1); add(r, x2 + 1, 1);
                }
            } else if (cmd[0] == 'Q') {
                scanf("%d%d", &x1, &y1);
                int res = sum(y1, x2);
                if (res & 1) puts("1");
                else puts("0");
            }
        }
    }
    return 0;
}
