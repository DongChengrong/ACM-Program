//ÌâÄ¿Á´½Ó£ºhttps://www.nowcoder.com/pat/6/problem/4048
#include <stdio.h>
#include <string.h>

#define N 110000

typedef long long ll;

char s[N];
char ch[] = "0123456789ABCDEFG";

int main() {
    ll a, b, c;
    while (scanf("%lld%lld%lld", &a, &b, &c) == 3) {
        int cnt = 0;
        a = a + b;
        while (a) {
            s[cnt++] = ch[a % c];
            a /= c;
        }
        for (int i = cnt - 1; i >= 0; --i)
            printf("%c", s[i]);
        puts("");
    }
    return 0;
}
