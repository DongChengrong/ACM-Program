#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b, c, d, op;
        scanf("%d %d %d %d %d", &op, &a, &b, &c, &d);
        int dd = __gcd(b, d);
        int lcm = b * d / dd;
        a = a * (lcm / b);
        c = c * (lcm / d);
        if (op) {
            int res_a = a + c;
            dd = __gcd(res_a, lcm);
            res_a /= dd; lcm /= dd;
            printf("%d/%d\n", res_a, lcm);
        } else {
            int res_a = a - c;
            dd = __gcd(abs(res_a), lcm);
            res_a /= dd; lcm /= dd;
            if (res_a < 0) printf("-");
            printf("%d/%d\n", abs(res_a), lcm);
        }
    }
    return 0;
}
