#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 502000
#define INF 0x3f3f3f3f

int f[N], len;
char s[N];

void getFail() {
    len = strlen(s);
    f[0] = f[1] = 0;
    for (int i = 1; i < len; ++i) {
        int j = f[i];
        while (j && s[i] != s[j]) j = f[j];
        f[i + 1] = (s[i] == s[j] ? j + 1 : 0);
    }
}

int main() {
    int res = INF;
    scanf("%s", s);
    getFail();
    for (int i = 1; i <= len; ++i)
        res = min(res, )
    printf("%d\n", f[len]);
    return 0;
}

ababbaba
bbababab
babababb
ababbaba



