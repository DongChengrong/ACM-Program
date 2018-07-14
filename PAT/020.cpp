//ÌâÄ¿Á´½Ó£ºhttps://www.nowcoder.com/pat/2/problem/4072
#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n / 100; ++i) printf("B");
        for (int i = 0; i < n % 100 / 10; ++i) printf("S");
        for (int i = 1; i <= n % 10; ++i) printf("%d",i);
        puts("");
    }
    return 0;
}
