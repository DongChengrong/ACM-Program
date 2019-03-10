#include <stdio.h>
#include <math.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int a = ceil((n * 1.0) / 2.0);
        int b = 0, c = 0;
        for (int i = 0; i < n; ++i) {
            int x; scanf("%d", &x);
            if (x > 0) b++;
            if (x < 0) c++;
        }
        if (b >= a) puts("1");
        else if (c >= a) puts("-1");
        else puts("0");
    }
    return 0;
}
