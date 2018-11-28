#include <stdio.h>
#include <string.h>

typedef long long ll;

#define N 1100
#define M 1100000

ll a[N], b[M], c[M];

int main() {
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF) {
        a[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            a[i] = a[i - 1] + a[i];
        }
        int m = 0;
        for (int i = 1; i <= n; ++i) {
            b[m++] = a[i] - a[i - 1];
            for (int j = i + 1; j <= n; ++j) {
                b[m++] = a[j] - a[i - 1];
            }
        }
        ll res = 0;
        for (int i = 40; i >= 0; --i) {   //�λö��
            int cnt = 0;
            for (int j = 0; j < m; ++j) {   //�ж�ĳһλ�ж��ٳ����˶��ٴ�
                if (b[j] & (1ll << i)) {   //��1����Сд��ll������111
                    c[cnt++] = b[j];
                }
            }
            if (cnt >= k) {
                for (int j = 0; j < cnt; ++j) b[j] = c[j];
                m = cnt;
                res = res + (1ll << i);
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
