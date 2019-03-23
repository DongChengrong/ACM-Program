//ÌâÄ¿Á´½Ó£ºhttp://118.190.20.162/view.page?gpid=T63
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int res = (n / 50) * 7;
    n = n % 50;
    res += 4 * (n / 30);
    n = n % 30;
    res += n / 10;
    printf("%d\n", res);
    return 0;
}
