#include <stdio.h>
#include <string.h>

#define N 27
#define M 110000

int sum[N][M];
char s[M];

int main() {
    int T, n, q;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        printf("Case #%d:\n", kase);
        memset(sum, 0, sizeof(sum));
        scanf("%d%d", &n, &q);
        scanf("%s", s);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) sum[j][i + 1] = sum[j][i];
            sum[s[i] - 'A'][i + 1] += 1;
        }
        while (q--) {
            int l, r, ans;
            scanf("%d%d", &l, &r);
            for (int i = 0; i < 26; ++i) {
                ans = sum[i][r] - sum[i][l - 1];
                if (ans) break;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
