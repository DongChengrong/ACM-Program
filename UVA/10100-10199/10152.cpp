/*
*分析：反过来推，最底下的一定是确定好的
*
*/
#include <stdio.h>
#include <string.h>

#define N 250

char s1[N][N], s2[N][N];

int main() {
    int T;
    scanf("%d", &T); getchar();
    while (T--) {
        int n;
        scanf("%d", &n); getchar();
        for (int i = 0; i < n; ++i) gets(s1[i]);
        for (int i = 0; i < n; ++i) gets(s2[i]);
        int l = n - 1, r = n - 1;
        while (l >= 0) {
            if (strcmp(s1[l], s2[r])) l--;
            else l--, r--;
        }
        while (r >= 0) puts(s2[r--]);
        puts("");
    }
    return 0;
}
