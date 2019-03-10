//ÌâÄ¿Á´½Ó£ºhttp://118.190.20.162/view.page?gpid=T78
#include <stdio.h>
#include <string.h>

#define N 1100000

int a[N], b[N];

int main() {
    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; ++i) {
        int l, r; scanf("%d%d", &l, &r);
        for (int i = l; i < r; ++i) a[i]++;
        a[r] += 2;
    }
    for (int i = 0; i < n; ++i) {
        int l, r; scanf("%d%d", &l, &r);
        for (int i = l; i < r; ++i) b[i]++;
        b[r] += 2;
    }
    int ans = 0, tmp = 0;
    for (int i = 0; i <= N; ++i) {
        //if (i < 15) printf("%d %d\n", i, tmp);
        if (a[i] == 1 && b[i] == 1) ++tmp;
        else{
           if (a[i] >= 1 && b[i] >= 1) ++tmp;
           if (tmp) ans += tmp - 1;
           tmp = 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}
