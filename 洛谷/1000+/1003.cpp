/*
*由于在本题中n小于1e4且只有一个点需要输出，所以我们可以从后往前找第一个覆盖住该点
*的地毯，如果没有输出-1
*@作者:董成荣
*/

#include <stdio.h>
#include <string.h>

#define N 11000

struct Node {
    int a, b, g, k;
}ma[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d%d%d", &ma[i].a, &ma[i].b, &ma[i].g, &ma[i].k);
        }
        int x, y, i;
        scanf("%d%d", &x, &y);
        for (i = n; i >= 1; i--) {
            if (x <= ma[i].a + ma[i].g && x >= ma[i].a &&
                y >= ma[i].b && y <= ma[i].b +ma[i].k) break;
        }
        printf("%d\n", i == 0 ? -1 : i);
    }
    return 0;
}
