/*
*�������GCD = LCM��𰸱�Ϊ1
*��Σ����GCD > LCM ����LCM % GCD ��= 0���
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
