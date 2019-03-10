#include <stdio.h>

int main() {
    int a, b, c = 19;
    while (scanf("%d%d", &a, &b) != EOF) {
        printf("%d\n", (a * 10 + b) / c);
    }
    return 0;
}
