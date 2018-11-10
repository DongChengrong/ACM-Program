#include <stdio.h>
#include <string.h>

#define N 110
#define Mod 10000007

typedef long long ll;

struct Matrix {
    ll a[N][N];
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
    Matrix c; memset(c.a, 0, sizeof(c.a));
    for (int i = 0; i < n; ++i) c.a[i][i] = 1;
    while (b) {
        if (b & 1) c = mul(c, a);
        a = mul(a, a);
        b = b >> 1;
    }
    return c;
}
