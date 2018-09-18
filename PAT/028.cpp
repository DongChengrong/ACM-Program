//ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805342720868352/problems/994805511923286016
#include <stdio.h>

int main() {
    int x, cur = 0, cost = 0;
    int n; scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        if (cur == x) { cost += 5; continue; }
        cost += (cur > x) ? (cur - x) * 4 + 5 : (x - cur) * 6 + 5;
        cur = x;
    }
    printf("%d\n", cost);
    return 0;
}
