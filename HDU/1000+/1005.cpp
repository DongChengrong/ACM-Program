#include <stdio.h>
#include <string.h>

#define N 2
#define Mod 7

const int n = 2;

struct Matrix {
    int a[N][N];
};

Matrix mul(Matrix a, Matrix b) {
    Matrix c; memset(c.a, 0, sizeof(c.a));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % Mod;
            }
        }
    }
    return c;
}

Matrix qpow(Matrix a, int b) {
    Matrix res; memset(res.a, 0, sizeof(res.a));
    for (int i = 0; i < n; ++i) res.a[i][i] = 1;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b = b >> 1;
    }
    return res;
}

int main() {
    int a, b, n;
    while (scanf("%d%d%d", &a, &b, &n) != EOF && (a + b + n)) {
        if (n == 1 || n == 2) { puts("1"); continue; }

        Matrix res;
        res.a[0][0] = a; res.a[0][1] = b;
        res.a[1][0] = 1; res.a[1][1] = 0;
        res = qpow(res, n - 2);
        printf("%d\n", (res.a[0][0] + res.a[0][1]) % Mod);
    }
    return 0;
}
