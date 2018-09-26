#include <stdio.h>
#include <string.h>

#define N 1001000

int f[N], len1, len2;
char s1[N], s2[N];

void getFail() {
    int i, j;
    len1 = strlen(s1);
    len2 = strlen(s2);
    f[0] = f[1] = 0;
    for (i = 1; i < len2; ++i) {
        j = f[i];
        while (j && s2[i] != s2[j]) j = f[j];
        f[i + 1] = (s2[i] == s2[j] ? j + 1 : 0);
    }
}

int main() {
    while (scanf("%s", s1) != EOF) {
        int i, j = 0;
        scanf("%s", s2);
        getFail();
        for (i = 0; i < len1; ++i) {
            while (j && s1[i] != s2[j]) j = f[j];
            if (s1[i] == s2[j]) ++j;
            if (j >= len2) {
                printf("%d\n", i - len2 + 2);
            }
        }
        for (i = 0; i < len2; ++i) printf("%d%c", f[i + 1], i == len2 - 1 ? '\n' : ' ');
    }
    return 0;
}
