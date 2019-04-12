#include <stdio.h>

#define N 110000

char s[N];

int main() {
    int n; scanf("%d", &n);
    scanf("%s", s);
    int cnt = 0;
    for (int i = 0; i < n; ++i) if (s[i] == 'R') ++cnt;
    if (cnt > (n - cnt)) puts("Yes");
    else puts("No");
    return 0;
}
