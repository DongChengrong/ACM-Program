//Ä£ÄâË®Ìâ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 15

char s[N];

int val() {
    int sum = 0;
    sum += 26 * 26 * (s[0] - 'A');
    sum += 26 * (s[1] - 'A');
    sum += 1 * (s[2] - 'A');
    return sum;
}

int main() {
    int T;
    scanf("%d", &T); getchar();
    while (T--) {
        int d, i;
        for (i = 0; i <= 2; ++i) s[i] = getchar(); getchar();
        scanf("%d", &d); getchar();
        printf("%s\n", abs(val() - d) <= 100 ? "nice" : "not nice");
    }
    return 0;
}
