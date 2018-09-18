#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 1100000
#define INF 0x3f3f3f3f

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, pre = -1, p, sum = 0, suf;
        scanf("%d", &n);
        scanf("%d", &p); n--;
        while (n--) {
            int tmp;
            scanf("%d", &tmp);
            if (pre == -1) pre = tmp - p - 1, sum += pre;
            else suf = tmp - p - 1, sum += suf;
            p = tmp;
        }

        printf("%d\n", sum - min(pre, suf)) ;
    }
    return 0;
}
