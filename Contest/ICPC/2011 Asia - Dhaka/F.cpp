#include <stdio.h>

int main() {
    int T, kase = 0;
    scanf("%d", &T);
    while(T--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a > 20 || b > 20 || c > 20) printf("Case %d: bad\n", ++kase);
        else printf("Case %d: good\n", ++kase);
    }
    return 0;
}
