/*
*首先如果GCD = LCM则答案必为1
*其次，如果GCD > LCM 或者LCM % GCD ！= 0则答案
**/
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll x, y;
    while (scanf("%lld%lld", &x, &y) != EOF) {
        if (x == y) {
            puts("1"); continue;
        }
        if (x > y || y % x != 0) { puts("0"); continue;}
        ll mn = y / x;
        int cnt = 0;
        for (ll m = 1; m <= mn; ++m) {
            if (mn % m != 0) continue;
            ll n = mn / m;
            if (__gcd(n, m) == 1) ++cnt;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
