#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 110000

typedef long long ll;

struct Node {
    ll a, b;
    bool operator < (const Node &u) const {
        return (a - b) > (u.a - u.b);
    }
};

Node a[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) scanf("%I64d%I64d", &a[i].a, &a[i].b);
        sort(a, a + n);
        ll res = 0;
        for (ll i = 0; i < n; ++i) {
            res += a[i].a * i +  a[i].b * (n - i - 1);
        }
        printf("%I64d\n", res);
    }
    return 0;
}
