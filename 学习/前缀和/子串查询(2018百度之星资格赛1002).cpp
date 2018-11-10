#include <stdio.h>
#include <string.h>

#define N 110000

int pre[26][N];  //记录前缀和
char str[N];  //字符串S

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        printf("Case #%d:\n", kase);

        int n, q;
        memset(pre, 0, sizeof(pre));
        scanf("%d%d", &n, &q);
        scanf("%s", str + 1);  //从str + 1开始存储字符串，便于之后的处理
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {  //对应一维数组中的pre[i] = pre[i - 1];
                pre[j][i] = pre[j][i - 1];
            }
            ++pre[str[i] - 'A'][i];
        }
        while (q--) {
            int l, r, sum;
            scanf("%d%d", &l, &r);
            for (int i = 0; i < 26; ++i) {
                sum = pre[i][r] - pre[i][l - 1];
                if (sum) break;
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}
