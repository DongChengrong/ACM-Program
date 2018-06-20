#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    while (scanf("%d%d",&n, &m) == 2) {
        double res = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            int flag; double x; scanf("%lf%d", &x, &flag); sum += x;
            if (flag) res += x * 0.8;
            else res += x;
        }
        while (m--) {
            double x, y;
            scanf("%lf%lf",&x, &y);
            if (sum >= x) {
                res = min(res, sum - y);
            }
        }
        printf("%.2f\n",res);
    }
    return 0;
}
