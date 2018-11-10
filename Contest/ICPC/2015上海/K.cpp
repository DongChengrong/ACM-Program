#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#define N 110000

typedef long long ll;

char s[N];
vector<ll> res;

int main() {
    int T;
//
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        printf("Case #%d: ", kase);
        res.clear();
        scanf("%s", s);
        ll sum = 0;
        int n = strlen(s);
        ll cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) ++cnt;
            else {
                sum += cnt * cnt;
                res.push_back(cnt); cnt = 1;
            }
        }
        res.push_back(cnt);
//        for (int i = 0; i <res.size(); ++i) printf("%d ", res[i]);
//        puts("");
        sum += cnt * cnt;
        ll ans = sum;
        for(int i = 0; i < res.size(); ++i) {
            if (i + 1 < res.size() && i + 2 < res.size() && res[i + 1] == 1) {
                ll tmp = sum - res[i] * res[i] - res[i + 1] * res[i + 1] - res[i + 2] * res[i + 2];
                ll t2 = res[i] + res[i + 1] + res[i + 2];
                tmp = tmp + t2 * t2;
                ans = max(ans, tmp);
            } else if (i + 1 < res.size()) {
                ll tmp = sum - res[i] * res[i] - res[i + 1] * res[i + 1];
                tmp = tmp + (res[i] + 1) * (res[i] + 1) + (res[i+1] - 1) * (res[i + 1] - 1);
                ans = max(tmp, ans);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
