#include <stdio.h>

#define N 210000

int a[N];

int main() {
    int n; scanf("%d", &n);
    int aa = 0, bb = 0;
    int i, c = 0, d = 0;
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i]) ++aa; else ++bb;
    }
    for (i = 0; i < n; ++i) {
        if (a[i]) ++c; else ++d;
        if (c >= aa || d >= bb) break;
    }
    printf("%d\n", i + 1);
    return 0;
}
