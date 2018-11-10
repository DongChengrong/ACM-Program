#include <stdio.h>

void print(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) printf("%d", i);
        puts("");
    }
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) printf("%d", i);
        puts("");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, v;
        scanf("%d%d", &n, &v);
        while (v--) {
            print(n);
            if (v) puts("");
        }
        if (T) puts("");
    }
    return 0;
}
