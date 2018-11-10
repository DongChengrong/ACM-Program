#include <stdio.h>
#include <math.h>

int main() {
    int n, T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", (int)sqrt(n / 6));
    }
    return 0;
}
