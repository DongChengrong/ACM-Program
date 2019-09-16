#include <stdio.h>
#include <string.h>

#define N 11000

char s[N];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n, i; scanf("%d", &n);
        scanf("%s", s);
        for (i = 0; i < n; ++i) if (s[i] == '8') break;
        if (n - i >= 11) puts("YES"); else puts("NO");
    }
    return 0;
}