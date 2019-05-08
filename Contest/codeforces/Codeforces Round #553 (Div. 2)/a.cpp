#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

#define N 110

int n;
char s[N];

int main() {
    while (scanf("%d", &n) != EOF) {
        int res = 1000000;
        scanf("%s", s);
        for (int i = 0; i < n - 3; ++i) {
            int tmp = 0;
            tmp += min(s[i] - 'A', 26 - (s[i] - 'A'));
            tmp += min(abs(s[i+1] - 'C'), 26 - abs(s[i+1] - 'C'));
            tmp += min(abs(s[i + 2] - 'T'), 26 - abs(s[i+2] - 'T'));
            tmp += min(abs(s[i + 3] - 'G'), 26 - abs(s[i + 3] - 'G'));
            res = min(res, tmp);
        }
        printf("%d\n", res);
    }
    return 0;
}