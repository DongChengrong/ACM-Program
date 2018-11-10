#include <stdio.h>
#include <string.h>

#define N 15
#define Mod 9973

typedef long long ll;

struct Matrix {
    ll a[N][N];
};

int n, k;

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
            for (int k = 0; k < n; ++k) {
                c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % Mod;
            }
        }
    }
    return c;
}

Matrix qpow(Matrix a, int k) {
    Matrix res; memset(res.a, 0, sizeof(res.a));
    for (int i = 0; i < n; ++i) res.a[i][i] = 1;
    while (k) {
        if (k & 1) res = mul(res, a);
        a = mul(a, a);
        k = k >> 1;
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        Matrix res;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%lld", &res.a[i][j]);
            }
        }
        //print_mat(res);
        res = qpow(res, k);
        ll sum = 0;
        //print_mat(res);
        for (int i = 0; i < n; ++i) {
            sum = (sum + res.a[i][i]) % Mod;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
