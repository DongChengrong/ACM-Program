/*
*ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805342720868352/problems/994805504927186944
**/
#include <stdio.h>
#include <algorithm>

using namespace std;

char c[8] = {'W', 'T', 'L' };
double a[13];
int b[5];

int main() {
    for (int i = 0; i < 3; ++i) {
        a[i] = -100;
        for (int j = 0; j < 3; ++j) {
            double tmp; scanf("%lf", &tmp);
            if (a[i] < tmp) {
                a[i] = tmp; b[i] = j;
            }
        }
    }
    printf("%c %c %c ", c[b[0]], c[b[1]], c[b[2]]);
    printf("%.2f\n", (a[0] * a[1] * a[2] * 0.65 - 1) * 2 );
    return 0;
}
