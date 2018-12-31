#include <stdio.h>

int main() {
    int a, t, v;
    while (scanf("%d%d", &v, &t) != EOF) {
        printf("%d\n", 2 * v * t);
    }
    return 0;
}
