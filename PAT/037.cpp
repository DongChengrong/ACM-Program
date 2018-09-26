//ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805260223102976/problems/994805282389999616
#include <stdio.h>
#include <string.h>

#define Mod 1000000007
#define N 110000

typedef long long ll;

char s[N];
ll dp[N][5];

int main() {
    while (scanf("%s", s + 1) != EOF) {
        int n = strlen(s + 1);
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][0]; dp[i][1] = dp[i - 1][1]; dp[i][2] = dp[i - 1][2];
            if (s[i] == 'P') dp[i][0] = (dp[i][0] + 1) % Mod;
            if (s[i] == 'A') dp[i][1] = (dp[i][1] + dp[i][0]) % Mod;
            if (s[i] == 'T') dp[i][2] = (dp[i][2] + dp[i][1]) % Mod;
        }
        printf("%lld\n", dp[n][2]);
    }
    return 0;
}
