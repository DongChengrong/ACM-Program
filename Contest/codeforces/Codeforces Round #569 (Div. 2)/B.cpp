#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define N 110000

int a[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int index = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (a[i] >= 0) a[i] = -a[i] - 1;
            if (i != 0 && abs(a[i]) > abs(a[index])) index = i;
        }
        if (n & 1) a[index] = -a[index] - 1;
        for (int i = 0; i < n; ++i) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}
