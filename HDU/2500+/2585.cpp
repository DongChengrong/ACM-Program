#include <stdio.h>
#include <string.h>

#define N 100

char s1[N], s2[N];

int main() {
    while (scanf("%s",s1) == 1) {

        while (s1 == "") scanf("%s",s1);

        int n, cnt = 0;
        scanf("%d",&n);
        int flag = false;
        while (n--) {
            scanf("%s",s2);
            int ok = 1,i = 0, j = 0;
            int len1 = strlen(s1);
            int len2 = strlen(s2);
            while (1) {
                if (i >= len1 && j >= len2) {
                    break;
                }
                if (i < len1 && j > len2) {
                    ok = 0; break;
                }
                if (i >= len1 && j < len2) {
                    ok = 0; break;
                }

                if (s1[i] == '?') {
                    ++i; ++j;
                } else if (s1[i] == '*') {
                    while (i <= len1) {
                        if (s1[i] == '*') ++i;
                        else break;
                    }
                    while (j <= len2) {
                        if (s2[j] != s1[i]) ++j;
                        else break;
                    }
                    if (s1[i] != s2[j]) {
                        ok = 0; break;
                    } else {
                        ++i; ++j;
                    }
                } else {
                    if (s1[i] == s2[j]) {
                        ++i; ++j;
                    } else {
                        ok = 0; break;
                    }
                }
            }
            if (ok) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
