//打着树的旗号进行贪心
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n < 6) {
            puts("-1");
        } else {
            puts("1 2"); puts("1 3"); puts("1 4");
            for (int i = 5; i <= n; ++i) printf("4 %d\n", i);
        }
        for (int i = 2; i <= n; ++i) printf("1 %d\n", i);
    }
    return 0;
}
