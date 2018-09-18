//ˮ
#include <stdio.h>

int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n > 4) printf("%d\n", n);
        else puts("4");
    }
    return 0;
}
