#include <stdio.h>
#include <string.h>

#define N 1100

char s[N];

int main() {
    int n; scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        int len = strlen(s), i, flag = 0, ok = 0;
        for (i = 0; i < len; ++i) {
            if (s[i] != 'P' && s[i] != 'A' && s[i] != 'T') flag = 1;
            if ((s[i] == 'P' && s[i + 1] == 'A' && s[i + 2] == 'T') \
                   || (s[i] == 'P' && s[i + 1] == 'A' && s[i + 2] == 'A' && s[i + 3] == 'T')) {
                ok = 1;
            } else if(s[i] == 'P' && s[i + 1] != 'A') flag = 1;
        }
        if (flag || (!ok)) puts("NO");
        else puts("YES");
    }
    return 0;
}
