#include <stdio.h>
#include <string.h>

#define N 110000

char s[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int x, y , res; x = y = res = 0;
        scanf("%s", s);
        int l = 0, r = 0;
        int n = strlen(s);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'U') ++y;
            if (s[i] == 'D') --y;
            if (s[i] == 'L') --x;
            if (s[i] == 'R') ++x;
            if (x > y) {
                if (i == 0) r = 1;
                else {
                    if (l) {
                        r = 1, l = 0;
                        ++res;
                    }
                }
            } else if (x < y) {
                if (i == 0) l = 1;
                if (r) {
                    r = 0, l = 1;
                    ++res;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
