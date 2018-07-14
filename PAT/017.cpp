#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 1100

int f[N], cnt;

void init() {
    f[0] = 1; cnt = 0;
    for (int i = 1; f[i - 1] <= 1000; ++i) {
        f[i] = f[i - 1] + 2 * (2 * i + 1);
        cnt = i;
    }
}

int main() {
    int n;
    char c;
    init();
    while (scanf("%d %c", &n, &c) != EOF) {
        int p = lower_bound(f, f + cnt, n) - f;
        if (f[p] != n) --p;
        for (int i = 1; i <= p; ++i) {
            for (int j = 0; j < i - 1; ++j) printf(" ");
            for (int j = 0; j < (2 * p + 1) - 2 * (i - 1); ++j) printf("%c", c);
            puts("");
        }
        for (int i = 0; i <= p; ++i) {
            for (int j = 0; j < (p - i); ++j) printf(" ");
            for (int j = 0; j < (2 * i + 1); ++j) printf("%c", c);
            puts("");
        }
        printf("%d\n", n - f[p]);
    }
    return 0;
}
