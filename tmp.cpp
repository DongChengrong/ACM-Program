//01±³°ü
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 11000

int w[N], c[N], dp[N];
char s[N];

int main() {
    int n, k, cnt;
    while (scanf("%d%d", &n, &k) != EOF) {
        int cnt = 0;
        scanf("%s", s);
        memset(w, 0, sizeof(w));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++cnt;
                while (i < n && s[i] == '1') { w[cnt]++; ++i; }
            }
        }
        for (int i = 1; i <= cnt; ++i) c[i] = 2;
        if (s[0] == '1') c[1] = 1;
        if (s[n - 1] == '1') c[cnt] = 1;
        if (k == 0) {
            if (s[0] == '1') printf("%d\n", w[1]);
            else puts("0");
            continue;
        }
        ++k;
        for (int i = 1; i <= cnt; ++i) {
            for (int j = k; j >= c[i]; --j) {
                dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
            }
        }
        printf("%d\n", dp[k]);
    }
    return 0;
}
