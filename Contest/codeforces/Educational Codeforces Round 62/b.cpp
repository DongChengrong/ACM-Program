#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 110

int n;
char s[N];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", s);
        int i = 0, j = n - 1;
        while (i < j) {
            if (s[i] == '>') break;
            if (s[j] == '<') break;
            ++i, --j;
        }
        int res;
        if (i == j) res = n / 2;
        else {
            if (i > j) res = n / 2;
            else res = min(i, n - 1 - j);
        }
        printf("%d\n", res);
    }
    return 0;
}
