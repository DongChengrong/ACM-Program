#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define N 110050

char s1[N], s[2 * N];
int len[2 * N];

int manachar() {
    int n = strlen(s1), m = 1;
    s[0] = '$';
    for (int i = 0; i < n; ++i) { s[m++] = '#'; s[m++] = s1[i]; } s[m++] = '#';
    int mx = 0, p, r = -1;
    for (int i = 1; i < m; ++i) {
        if (mx > i) len[i] = min(len[2 * p - i], mx - i);
        else len[i] = 1;
        while (s[i - len[i]] == s[i + len[i]]) ++len[i];
        if (len[i] + i > mx) mx = len[i] + i, p = i;
        r = max(len[i], r);
    }
    return r - 1;
}

int main() {
    while (scanf("%s", s1) != EOF) {
        if (!strcmp(s1, "")) continue;
        printf("%d\n", manachar());
    }
    return 0;
}
