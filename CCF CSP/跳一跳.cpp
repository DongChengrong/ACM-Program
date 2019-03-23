//ÌâÄ¿Á´½Ó£ºhttp://118.190.20.162/view.page?gpid=T73
#include <stdio.h>

int main() {
    int res = 0, way, score = 1;
    while (scanf("%d", &way) != EOF && way) {
        if (way == 1) {
            score = 1;
        } else if (way == 2) {
            if (score == 1) score = 2;
            else score += 2;
        }
        res += score;
    }
    printf("%d\n", res);
    return 0;
}
