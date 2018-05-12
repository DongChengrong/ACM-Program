#include <stdio.h>

typedef long long ll;

int main() {
    ll n;
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    while (scanf("%lld",&n) == 1) {
        printf("%lld\n",n / 5);
    }
    return 0;
}
