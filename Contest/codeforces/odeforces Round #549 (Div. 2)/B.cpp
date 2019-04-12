#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 32

typedef long long ll;

char s[N];

ll pow(ll a, int n) {
    ll res = 1;
    for (int i = 0; i < n; ++i) res = res * a;
    return res;
}

int main() {
    scanf("%s", s);
    int n = strlen(s);
    ll d = 1;
    ll res = pow(9, n - 1);
    for (int i = 0; i < n; ++i) {
        res = max(res, (ll)(d * pow(9, n - i - 1) *(s[i] - '1')));
        d = d * (s[i] - '0');
    }
    printf("%I64d\n", max(res, d));
    return 0;
}
