#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define N 1100
#define Mod 10007

typedef long long ll;

ll f[N][N];
ll a, b, n, k, m;

ll qpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a % Mod;

    ll ans = qpow(a, b / 2) % Mod;

    ans = (ans * ans) % Mod;
    if (b & 1) ans = (ans * a) % Mod;
    return ans % Mod;
}

void init() {
    for (int i = 0; i < N; ++i) {
        f[i][0] = 1; f[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % Mod;
        }
    }
//    f[0] = f[1] = 1;
//    for (int i = 2; i < N; ++i) f[i] = (f[i - 1] * i) % Mod;
}

//ll C(ll n, ll k) {
//    ll tmp = qpow(f[k], Mod - 2) % Mod;
//    return (f[n] * tmp) % Mod;
//}

int main() {
    init();
    //printf("%lld\n",f[3][1]);
    while (scanf("%lld%lld%lld%lld%lld", &a, &b, &k, &n, &m) == 5) {
        ll res = f[k][m] % Mod;
        res = (res * qpow(b, m)) % Mod;
        res = (res * qpow(a, n)) % Mod;
        printf("%lld\n",res % Mod);
    }
    return 0;
}
