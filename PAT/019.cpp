//ÌâÄ¿Á´½Ó:https://www.nowcoder.com/pat/2/problem/267
#include <stdio.h>
#include <string.h>

#define N 110000

typedef long long ll;

int main() {
    int n, r;
    while (scanf("%lld%d", &n, &r) == 2) {
        int cnt = 0;
        while (n) {
            if (n % r == 1) cnt++;
            n /= r;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
