#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 1100

int dp[N];

int main() {
    dp[1] = 1;
    for (int i = 2; i <= 100; ++i) dp[i] = dp[i - 1] + (i - 1) * 4;
    int x;
    while (scanf("%d", &x) != EOF) printf("%d\n", dp[x]);
    return 0;
}
