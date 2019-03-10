#include <stdio.h>

#define N 15

int t[N];

int main() {
    int day = 0, i;
    for (i = 1; i <= 7; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        t[i] = (a + b - 8) <= 0 ? 0 : (a + b - 8);
    }
    for (i = 1; i <= 7; ++i) {
        if (t[day] < t[i]) day = i;
    }
    printf("%d\n", day);
    return 0;
}
