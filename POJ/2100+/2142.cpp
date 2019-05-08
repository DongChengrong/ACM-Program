#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int a, b, d, g;

void exgcd(int a, int b, int &d, int &x, int &y) {
    if (!b) { d = a; x = 1; y = 0; }
    else { exgcd(b, a % b, d, y, x); y -= x * (a / b); }
}

void deal(int a, int b, int &x, int &y) {
    exgcd(a, b, g, x, y);
    int bb = b / g;
    x = (x * d / g % bb + bb) % bb;
    y = abs( (a*x - d) / b);
}

int main() {
    while (scanf("%d%d%d", &a, &b, &d) != EOF &&(a + b + d)) {
        int x1, x2, y1, y2;
        deal(a, b, x1, y1); deal(b, a, x2, y2);
        if ((x1 + y1) < (x2 + y2)) {
            printf("%d %d\n", x1, y1);
        } else printf("%d %d\n", y2, x2);
    }
    return 0;
}
