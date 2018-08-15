//¹þÏ£
#include <stdio.h>
#include <string.h>

#define N 256
#define M 11000

int a[N];
char s[M];

int main() {
    while (gets(s)) {
        int n = strlen(s), FRE = 0;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') continue;
            int p = (int)s[i];
            a[p]++;
            if (a[p] > FRE) FRE = a[p];
        }
        for (int i = 'A'; i < 'Z'; ++i) if (a[i] == FRE) printf("%c", i);
        for (int i = 'a'; i < 'z'; ++i) if (a[i] == FRE) printf("%c", i);
        printf(" %d\n", FRE);
    }
    return 0;
}
