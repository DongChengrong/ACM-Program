#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 110

typedef long long ll;

int num[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        ll n;
        scanf("%lld", &n);
        if (n == 1) puts("1");
        else {
            int cnt = 0;
            if (n != 1) {
                for (int i = 9; i >= 2; --i) {
                    if (n % i == 0) {
                        num[cnt++] = i;
                        n /= i;
                    }
                    if (n == 1) break;
                }
            }
            if (n != 1) puts("-1");
            else {
                sort(num, num + cnt);
                for (int i = 0; i < cnt; ++i) {
                    printf("%d", num[i]);
                }
                puts("");
            }

        }
    }
    return 0;
}
