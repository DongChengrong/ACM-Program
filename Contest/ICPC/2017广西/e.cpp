#include <stdio.h>
#include <string.h>

using namespace std;

typedef long long ll;

#define N 100

ll base[100] = {0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296,8589934592, 0, 0,0};

int n, q, b[N];
ll a[1000000];
ll sum;

void _do(ll x) {
    int cnt = 1;
    while (x) {
        if (x & 1) {
            b[cnt]++;
        }
        ++cnt;
        x = x >> 1;
    }
}

void _do2(ll x) {
    int cnt = 1;
    while (x) {
        if (x & 1) {
            --b[cnt];
        }
        ++cnt;
        x = x >> 1;
    }
}

void print(ll x) {
    _do2(x);
    ll res = 0;
    for (int i = 1; i <= 32; ++i) {
        if (b[i] == n - 1) res += base[i];
    }
    printf("%lld ", res); res = 0;
    for (int i = 1; i <= 32; ++i) {
        if (b[i]) res += base[i];
    }
    _do(x);
    printf("%lld %lld\n", res, sum ^ x);
}

int main() {

    //freopen("in.txt", "r", stdin);

    while (scanf("%d%d", &n, &q) != EOF) {
        memset(b, 0, sizeof(b)); sum = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]); _do(a[i]); sum ^= a[i];
        }
        while (q--) {
            int tmp; scanf("%d", &tmp);
            print(a[tmp]);
        }
    }
    return 0;
}
