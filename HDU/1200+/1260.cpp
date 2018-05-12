#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 2200

int T,n;
int a[N], b[N],dp[N];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d",&a[i]);
        }
        for (int i = 1; i <= n - 1; ++i) {
            scanf("%d",&b[i]);
        }

        dp[1] = a[1];
        for (int i = 2; i <= n; ++i) {
            dp[i] = min(a[i] + dp[i - 1], dp[i - 2] + b[i - 1]);
        }

        int time = dp[n];
        int second = time % 60; time /= 60;
        int min = time % 60; time /= 60;
        int hour = time + 8;

        printf("%02d:%02d:%02d %s\n",hour, min, second, hour >= 12 ? "pm" : "am");
    }
    return 0;
}
