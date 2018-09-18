#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        if (a > b) swap(a, b);
        int k = b - a;
        int tmp = (k * (1 + sqrt(5)) / 2);
        if (tmp == a) puts("0");
        else puts("1");
    }
    return 0;
}
