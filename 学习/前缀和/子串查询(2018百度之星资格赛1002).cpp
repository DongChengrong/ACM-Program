#include <stdio.h>
#include <string.h>

#define N 110000

int pre[26][N];  //��¼ǰ׺��
char str[N];  //�ַ���S

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        printf("Case #%d:\n", kase);

        int n, q;
        memset(pre, 0, sizeof(pre));
        scanf("%d%d", &n, &q);
        scanf("%s", str + 1);  //��str + 1��ʼ�洢�ַ���������֮��Ĵ���
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {  //��Ӧһά�����е�pre[i] = pre[i - 1];
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
