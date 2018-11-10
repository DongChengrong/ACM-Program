#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a < b) puts("<");
        else if (a == b) puts("=");
        else puts(">");
    }
    return 0;
}
