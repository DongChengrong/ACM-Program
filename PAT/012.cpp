//ÌâÄ¿Á´½Ó£ºhttps://www.nowcoder.com/pat/6/problem/4062
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char c;
    while (scanf("%d %c", &n, &c) != EOF) {
        for (int i = 1; i <= (n + 1) / 2; ++i) {
            printf("%c", c);
            for (int j = 2; j <= n - 1; ++j) {
                printf("%c", i == 1 || i == (n + 1) / 2 ? c : ' ');
            }
            printf("%c", c);
            puts("");
        }
    }
    return 0;
}
