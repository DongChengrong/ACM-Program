#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            sum += (x <= 1 ? 0 : x - 1);
        }
        printf("%d\n", sum);
    }
    return 0;
}
