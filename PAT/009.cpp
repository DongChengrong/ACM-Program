//ÌâÄ¿Á´½Ó£ºhttps://www.nowcoder.com/pat/2/problem/268

#include <stdio.h>
#include <string.h>

#define N 110000

char s[N];
char ch[] = "0123456789ABCDEF";

int main() {
    int n, r;
    while (scanf("%d%d", &n, &r) == 2) {
        int cnt = 0;
        while (n) {
            s[cnt++] = ch[n % r];
            n /= r;
        }
        for (int i = cnt - 1; i >= 0; --i)
            printf("%c", s[i]);
        puts("");
    }
    return 0;
}
