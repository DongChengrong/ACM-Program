#include <stdio.h>
#include <string.h>

#define N 15

typedef long long ll;

ll Mod, k;

const int n = 10;

struct Matrix {
    ll a[N][N];
};

void print_mat(Matrix a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%lld ", a.a[i][j]);
        }
        puts("");
    }
}

Matrix mul(Matrix a, Matrix b) {
    Matrix c; memset(c.a, 0, sizeof(c.a));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k)
                c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % Mod;
        }
    }
    return c;
}

Matrix qpow(Matrix a, ll b) {
    Matrix res; memset(res.a, 0, sizeof(res.a));
    for (int i = 0; i < n; ++i) res.a[i][i] = 1;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int main() {
    while (scanf("%lld%lld", &k, &Mod) != EOF) {
        if (k < 10) { printf("%lld\n", k); continue; }

        ll res = 0;
        Matrix a; memset(a.a, 0, sizeof(a.a));
        for (int i = 0; i < n; ++i) scanf("%lld", &a.a[0][i]);
        for (int i = 1; i < n; ++i) a.a[i][i - 1] = 1;
        a = qpow(a, k - 10 + 1);
        for (int i = 0; i < n; ++i) {
            res = (res + a.a[0][i] * (9 - i)) % Mod;
        }
        printf("%lld\n", res);
    }
    return 0;
}
