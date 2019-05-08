#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

#define N 2100000

string t1, t2;
char s1[N], s2[N];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        t1.clear(); t2.clear();
        int l = -1, r = -1, flag = 0;
        scanf("%s", s1);
        scanf("%s", s2);
        int n = strlen(s1);
        int m = strlen(s2);
        if (n != m) { puts("0"); continue; }
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                if (l == -1) { l = i, r = i; }
                else r = i;
            }
        }
        if (l == -1) { printf("%d\n", n); continue; }
        for (int i = l; i <= r; ++i) {
            t1 += s1[i]; t2 += s2[i];
        }
        reverse(t1.begin(), t1.end());
        if (t1 != t2) { puts("0"); continue; }
        int res = 1;
        for (int i = 1; ; ++i) {
            if (l - i >= 0 && r + i < n) {
                if (s1[l - i] == s1[r + i]) ++res;
                else break;
            } else break;
        }
        printf("%d\n", res);
    }
    return 0;
}
