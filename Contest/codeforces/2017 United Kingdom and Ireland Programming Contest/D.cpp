#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, res = 0;
        scanf("%d", &n);
        while (n--) {
            int x;
            scanf("%d", &x);
            if (x) ++res;
        }
        printf("%d\n", res);
    }
    return 0;
}
