#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 220000
#define M 20

int ans[N];
int a[N], nex[N], last[N], step[N][M];
int n, m, q;

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) nex[a[i]] = (i == n ? a[1] : a[i + 1] );
    for (int i = 1; i <= n; ++i) last[i] = m + 1;
    for (int i = 1; i <= m; ++i) scanf("%d", &a[i]);
    ans[m + 1] = m + 1;
    for (int i = 0; i < 20; ++i) step[m + 1][i] = m + 1;
    for (int i = m; i >= 1; --i) {
        step[i][0] = last[nex[a[i]]];
        last[a[i]] = i;
        for (int j = 1; j < 20; ++j) step[i][j] = step[step[i][j - 1]][j - 1];
        int p = i, num = n - 1;
        for (int j = 19; j >= 0; --j) {
            if (num >= (1 << j)) {
                //printf("%d %d %d\n", p, j, step[i][j]);
                p = step[p][j];
                num -= (1 << j);
            }
        }
        ans[i] = min(ans[i + 1], p);
    }
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (ans[l] <= r) putchar('1'); else putchar('0');
    }
    puts("");
    return 0;
}
