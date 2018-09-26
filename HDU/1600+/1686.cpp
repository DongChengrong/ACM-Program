#include <stdio.h>
#include <string.h>

#define M 11000
#define N 1100000

int next[M];
char s[M], t[N];

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
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s); scanf("%s", t);
        getFail(s);
        int len1 = strlen(s);
        int len2 = strlen(t);
        int j = 0, cnt = 0;
        //for (int i = 0; i <= len1; ++i) printf("%d ", next[i]);
        for (int i = 0; i < len2; ++i) {
            while (j && s[j] != t[i]) j = next[j];
            if (s[j] == t[i]) ++j;
            if (j == len1) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
