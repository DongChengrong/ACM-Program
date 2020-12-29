#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

ll equilibrium() {
    ll wl, dl, wr, dr;
    scanf("%lld%lld%lld%lld", &wl, &dl, &wr, &dr);
    if (wl == 0) wl = equilibrium();
    if (wr == 0) wr = equilibrium();
    if (wl == -1 || wr == -1) return -1;
    if (wl * dl != wr * dr) return -1;
    return wl + wr;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        if (equilibrium() != -1) printf("YES\n");
        else printf("NO\n");
        if (T) printf("\n");
    }
    return 0;
}
