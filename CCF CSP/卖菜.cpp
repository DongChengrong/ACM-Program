//ÌâÄ¿Á´½Ó£ºhttp://118.190.20.162/view.page?gpid=T79
#include <stdio.h>

const int maxn = 1e3 + 10;

int a[maxn], b[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        int sum = a[i], tot = 1;
        if (i != 1) sum += a[i - 1], tot++;
        if (i != n) sum += a[i + 1], tot++;
        b[i] = sum / tot;
    }
    for (int i = 1; i <= n; ++i) printf("%d%c", b[i], i == n ? '\n' : ' ');
    return 0;
}
