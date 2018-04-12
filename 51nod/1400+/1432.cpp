#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 1000000

typedef long long LL;

LL a[N];

int main() {
    LL n, m;
    while (scanf("%lld%lld",&n, &m) == 2) {

        for (int i = 0; i < n; ++i) {
            scanf("%lld",&a[i]);
        }

        sort(a, a + n);

        int i = 0;
        int j = n - 1;
        int ans = 0;
        while (i <= j) {
            if(i == j) {
                ++ans;
                break;
            }

            if (a[i] + a[j] > m) {
                j--;
            } else {
                j--; ++i;
            }
            ++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}
