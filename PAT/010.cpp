//ÌâÄ¿Á´½Ó£ºhttps://www.nowcoder.com/pat/2/problem/274

#include <stdio.h>

typedef long long ll;

ll f[30];

int main() {
    int n;
    f[2] = 1; f[1] = 0;
    for (int i = 3; i <= 20; ++i) f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
    while (scanf("%d", &n) == 1) {
        printf("%lld\n",f[n]);
    }
    return 0;
}
