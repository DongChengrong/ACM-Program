#include <stdio.h>

#define N 16

int a[N][N];

int main() {
    int T; scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        for (int i = 0; i < 3; ++i) for (int j = 0;j < 4; ++j) scanf("%d", &a[i][j]);
        int a1, a2;
        for (int i = 0; i < 4; ++i) if (a[0][i]) a1 = a[0][i];
        for (int i = 0; i < 4; ++i) if (a[2][i]) a2 = a[2][i];
        if (a1 != a2) {
            puts("No!"); if (kase % 50 == 0) puts(""); continue;
        }
        int ok = 0;
        for (int i = 0; i < 4; ++i) {
            int l = (i + 4 - 1) % 4;
            int r = (i + 1) % 4;
            int t = (i + 2) % 4;
            if (a[1][l] == a[1][r] && a[1][i] == a[1][t]) { ok = 1; break; }
        }
        if (ok) puts("Yes!");
        else puts("No!");
        if (kase % 50 == 0) puts("");
    }
    return 0;
}
