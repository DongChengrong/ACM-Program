#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int l, r, a;
    while (scanf("%d%d%d", &l, &r, &a) != EOF) {
        int res = 0;
        res += min(l, r);
        int k = max(l, r) - min(l, r);
        res += min(k, a);
        if (a > k) {
            a -= k;
            res += a / 2;
        }
        printf("%d\n", res * 2);
    }
    return 0;
}
