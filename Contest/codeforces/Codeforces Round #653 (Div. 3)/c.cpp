#include <stdio.h>
#include <string.h>

#define N 11000

char s[N];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        scanf("%s", s);
        int cur = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') ++cur;
            else {
                if (cur <= 0) {
                    ++res;
                }
                else --cur;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
