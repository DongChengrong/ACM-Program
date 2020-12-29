#include <stdio.h>

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int x, y, n;
        scanf("%d%d%d", &x, &y , &n);
        n = n - y;
        int t = n / x;
        printf("%d\n", t * x + y);
    }
    return 0;
}
