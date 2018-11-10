#include <stdio.h>
#include <string.h>

#define N 15
#define Mod 1000000007

typedef long long ll;

const int n = 4;

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
            for (int k = 0; k < n; ++k) {
                c.a[i][j] = (((c.a[i][j] + a.a[i][k] * b.a[k][j]) % Mod) + Mod) % Mod;
            }
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
    ll k;

    while (scanf("%lld", &k) != EOF) {
        ll val[N] = {0, 1, 5, 11, 36}, sum = 0;
        if (k <= 4) { printf("%lld\n", val[k]); continue; }

        Matrix res; memset(res.a, 0, sizeof(res.a));
        res.a[0][0] = 1; res.a[0][1] = 5; res.a[0][2] = 1; res.a[0][3] = -1;
        for(int i = 1; i < n; ++i) res.a[i][i - 1] = 1;

        res = qpow(res, k - 4);
        for (int i = 0; i < n; ++i) {
            sum = (sum + res.a[0][i] * val[4 - i]) % Mod;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
