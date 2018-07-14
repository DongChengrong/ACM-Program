/*
Á´½Ó:https://www.nowcoder.com/pat/6/problem/4077
*/
#include <stdio.h>

typedef long long ll;

int main() {
    int T, kase = 0;
    scanf("%d", &T);
    while (T--) {
        ll a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("Case #%d: %s\n", ++kase, a + b > c ? "true" : "false");
    }
    return 0;
}
