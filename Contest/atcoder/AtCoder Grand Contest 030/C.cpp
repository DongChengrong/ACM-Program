#include <stdio.h>

int main() {
    int n;

    //freopen("out.txt", "w", stdout);

    while (scanf("%d", &n) != EOF) {
        printf("%d\n", n);
        if (n <= 500) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    printf("%d%c", j, j == n ? '\n' : ' ');
                }
            }
        } else {
            int m = n / 2;
            printf("%d\n", m);
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (i & 1) printf("%d", j);
                    else printf("%d", m + j);
                    printf("%c",j == m ? '\n' : ' ');
                }
            }
        }
    }
    return 0;
}
