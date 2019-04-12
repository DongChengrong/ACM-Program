#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 220000

struct Node {
    char a, b;
};

int n, m;
char s[N];
Node a[N];

int main() {
    scanf("%d%d", &n, &m); getchar();
    scanf("%s", s + 1); getchar();
    for (int i = 0; i < m; ++i) {
        scanf("%c %c", &a[i].a, &a[i].b); getchar();
    }
    int l = 1, r = n;
    for (int i = m - 1; i >= 0; --i) {
        if (a[i].b == 'L') {
            if (a[i].a == s[l]) ++l;
            if (r < n && a[i].a == s[r + 1]) ++r;
        } else if (a[i].b == 'R') {
            if (a[i].a == s[r]) --r;
            if (l > 1 && a[i].a == s[l - 1]) --l;
        }
    }
    printf("%d\n", max(r - l + 1, 0));
    return 0;
}
