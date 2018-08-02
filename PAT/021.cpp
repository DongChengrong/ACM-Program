//ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805342720868352/problems/994805528788582400
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ll a, b, c;
    vector<int> res;
    while (scanf("%lld%lld", &a, &b) != EOF) {
        c = a + b;
        if (c == 0) {
            puts("0");
            continue;
        }
        res.clear();
        if (c < 0) printf("-"), c = -1 * c;
        while (c) {
            res.push_back(c % 10);
            c /= 10;
        }
        for (int i = res.size() - 1; i >= 0; --i) {
            printf("%d", res[i]);
            if (i > 0 && i % 3 == 0) {
                printf(",");
            }
        }
        puts("");
    }
    return 0;
}
