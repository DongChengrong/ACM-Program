//ÌâÄ¿Á´½Ó£ºhttps://www.nowcoder.com/pat/6/problem/4052

#include <stdio.h>

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) == 2) {
        int ans = (b - a + 50) / 100;
        int h = ans / 3600;
        int m = ans % 3600 / 60;
        int s = ans % 60;
        printf("%s%0d:%s%d:%s%d\n", h < 10 ? "0" : "", h, m < 10 ? "0" : "", m, s < 10 ? "0" : "", s);
    }
    return 0;
}
