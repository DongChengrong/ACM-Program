#include <stdio.h>

int main() {
    int a, b, c, d;
    while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
        int minn = (c * 60 + d - a * 60 - b);
        printf("%d %d\n", minn / 60 , minn % 60);
    }
    return 0;
}
