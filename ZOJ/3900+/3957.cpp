#include <stdio.h>
#include <string.h>

#define N 1100
#define _for(i, a, b) for (int i = (a); i < (b); ++i)

char s[N];

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        int ans = 0;
        int i = 0;
        scanf("%s",s);
        int n = strlen(s);
        while (i < n) {
            if (s[i] == 'd') {
                if (s[i + 1] == 'o' && s[i + 2] == 'g') { ans++; i += 3; }
                else ++i;
            } else if (s[i] == 'c') {
                if (s[i + 1] == 'a' && s[i + 2] == 't') { ans++; i += 3; }
                else ++i;
            } else {
                ++i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
