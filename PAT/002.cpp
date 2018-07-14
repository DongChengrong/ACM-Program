/*
*ÌâÄ¿Á´½Ó£ºhttps://www.nowcoder.com/pat/6/problem/4042
*/
#include <stdio.h>

int num(int x, int xx) {
    int ans = 0;
    while (x) {
        if (x % 10 == xx) ans = ans * 10 + xx;
        x /= 10;
    }
    return ans;
}

int main() {
    int a, aa, b, bb;
    while (scanf("%d%d%d%d", &a, &aa, &b, &bb) != EOF) {
        printf("%d\n", num(a, aa) + num(b, bb));
    }
    return 0;
}
