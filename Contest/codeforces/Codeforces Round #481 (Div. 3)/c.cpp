#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 1100000

typedef long long ll;

ll a[N];
ll n, m;

int main() {
    while (cin >> n >> m) {
        a[0] = 1;
        for (int i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            a[i + 1] = a[i] + x;
        }

        for (int i = 0; i < m; ++i) {
            ll x;
            cin >> x;
            int p = upper_bound(a, a + n, x) - a;
            p--;
            cout << p + 1<< ' ' << x - a[p] + 1 << '\n';
        }
    }
    return 0;
}