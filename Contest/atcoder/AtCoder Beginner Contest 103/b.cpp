#include <stdio.h>
#include <string.h>

#define N 1100

char s[N], t[N];

int main() {
    while (scanf("%s%s", s, t) != EOF) {
        int ok = 0;
        int n = strlen(s);
        for (int i = 0; i < n; ++i) {
            if (ok) break;
            ok = 1;
            for (int j = 0; j < n; ++j) {
                if (s[(i + j) % n] != t[j]) ok = 0;
            }
        }
        if (ok) puts("Yes");
        else puts("No");
    }
    return 0;
}
