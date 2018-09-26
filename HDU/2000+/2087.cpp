#include <stdio.h>
#include <string.h>

#define N 1100

int next[N];
char s[N], t[N];

void getFail(char s[]) {
    int n = strlen(s);
    next[0] = next[1] = 0;
    for (int i = 1; i < n; ++i) {
        int j = next[i];
        while (j && s[j] != s[i]) j = next[j];
        next[i + 1] = (s[i] == s[j] ? j + 1 : 0);
    }
}

int main() {
    while (scanf("%s", t) != EOF && t[0] != '#') {
        scanf("%s", s);
        getFail(s);
        int j = 0, cnt = 0;
        int n = strlen(t);
        int m = strlen(s);
        for (int i = 0; i < n; ++i) {
            while (j && s[j] != t[i]) j = next[j];
            if (t[i] == s[j]) ++j;
            if (j == m) {
                cnt++; j = 0;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
