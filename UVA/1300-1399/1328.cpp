#include <stdio.h>
#include <string.h>

#define N 1100000

char s[N];
int f[N];

struct Node {
    int x, y;
    bool operator < (const Node &u) const {
        return y > u.y;
    }
};

int main() {
    int n, kase = 0;
    while (scanf("%d", &n) == 1 && n) {
        printf("Test case #%d\n", ++kase);
        scanf("%s", s);
        f[0] = 0; f[1] = 0;
        for (int i = 1; i < n; ++i) {
            int j = f[i];
            while (j && s[i] != s[j]) j = f[j];
            f[i + 1] = (s[i] == s[j] ? j + 1 : 0);
        }

        for (int i = 2; i <= n; ++i) {
            if (f[i] > 0 && i % (i - f[i]) == 0) printf("%d %d\n", i, i / (i - f[i]));
        }
        puts("");
    }
    return 0;
}
