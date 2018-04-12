#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 1100

int t[N];

int main() {
    int T, n;
    scanf("%d",&T);
    while (T--) {

        scanf("%d",&n);
        int a1 = 0, a2 = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d",&t[i]);
            a2 += t[i];
        }

        sort(t, t + n);

        int ans = 0;
        while (n) {
            if (n == 1) {
                ans += t[0];
                break;
            } else if (n == 2) {
                ans += t[1];
                break;
            } else if (n == 3) {
                ans += t[2] + t[0] + t[1];
                break;
            } else {
                ans += min( (t[n - 1] + t[n - 2] + 2 * t[0] ) , (t[n - 1] + 2 * t[1] + t[0]) );
                n -= 2;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
