#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const double esp = 1e-8;

double H, h, D;

double cal(double x) {
    double len = (D - x) - (H - h) * D / x + H;
    return len;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lf%lf%lf", &H, &h, &D);
        double l = D - D * h / H, r = D;
        while (l + esp < r) {
            double midl = (l + r) / 2;
            double midr = (midl + r) / 2;
            double len1 = cal(midl);
            double len2 = cal(midr);
            if (len1 >= len2) r = midr;
            else l = midl;
        }
        printf("%.3f\n", max(cal(l), cal(r)));
    }
    return 0;
}
