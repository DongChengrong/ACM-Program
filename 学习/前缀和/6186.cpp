#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 110000

int a[N];
int pre[3][N];
int suf[3][N];

int main() {
    int n, q;
    while (scanf("%d%d", &n, &q) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            pre[0][i] = (i == 0 ? a[i] : pre[0][i - 1] & a[i]);
            pre[1][i] = (i == 0 ? a[i] : pre[1][i - 1] | a[i]);
            pre[2][i] = (i == 0 ? a[i] : pre[2][i - 1] ^ a[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            suf[0][i] = (i == n - 1 ? a[i] : suf[0][i + 1] & a[i]);
            suf[1][i] = (i == n - 1 ? a[i] : suf[1][i + 1] | a[i]);
            suf[2][i] = (i == n - 1 ? a[i] : suf[2][i + 1] ^ a[i]);
        }
        while (q--) {
            int p; scanf("%d", &p); p = p - 1;
            if (p == 0) printf("%d %d %d\n", suf[0][1], suf[1][1], suf[2][1]);
            else if (p == n - 1) printf("%d %d %d\n", pre[0][n - 2], pre[1][n - 2], pre[2][n - 2]);
            else printf("%d %d %d\n", pre[0][p - 1] & suf[0][p + 1],
                         pre[1][p - 1] | suf[1][p + 1], pre[2][p - 1] ^ suf[2][p + 1]);
        }
    }
    return 0;
}
