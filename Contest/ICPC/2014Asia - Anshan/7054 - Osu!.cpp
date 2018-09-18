#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        double t1, x1, y1;
        double res = 0, t, x, y;
        scanf("%d", &n);
        scanf("%lf%lf%lf", &t, &x, &y); n--;
        while (n--) {
            scanf("%lf%lf%lf", &t1, &x1, &y1);
            res = max(sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)) / (t1 - t), res);
            t = t1, x = x1, y = y1;
        }
        printf("%.10f\n", res);
    }
    return 0;
}
