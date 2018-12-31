#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) != EOF) {
        if (c - a > 2) c = a + 2;
        if (c - b > 1) c = b + 1;
        else b = c - 1;
        if (b - a > 1) b = a + 1;
        else a = b - 1;
        printf("%d\n", a + b + c);
    }
    return 0;
}
