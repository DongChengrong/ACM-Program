#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int n, maxval;
int a[N], b[N];

int main() {
    while (scanf("%d", &n) != EOF) {
        maxval = -1;
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; ++i) {
            int tmp; scanf("%d", &tmp);
            ++b[tmp];
            if (tmp > maxval) maxval = tmp;
        }
        int res = 0;
        for (int i = 1; i <= maxval; ++i) {
            if (b[i]) {
                res += (b[i] / 2); b[i] %= 2;
                if (b[i] && b[i + 1] % 2 && b[i + 2]) {
                    ++res; b[i + 1]--; b[i + 2]--;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
