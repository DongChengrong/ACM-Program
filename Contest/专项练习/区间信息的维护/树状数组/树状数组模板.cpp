#include <stdio.h>
#include <string.h>

#define N 110000

int c[N];
int n;

int sum(int x) {
    int res = 0;
    while (x) {
        res += c[x];
        x -= x & (-x);
    }
    return res;
}

void add(int x, int d) {
    while (x <= n) {
        c[x] += d;
        x += x & (-x);
    }
}


int main() {
    while (scanf("%d", &n) != EOF) {
        memset(c, 0, sizeof(c));
    }
    return 0;
}
