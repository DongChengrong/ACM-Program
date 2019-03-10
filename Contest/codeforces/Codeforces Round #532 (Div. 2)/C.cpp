#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define PI 3.1415926
#define _for(i, a, b) for (int i = (a); i < (b); ++i)

typedef long long ll;

int main() {
    double n, r;
    scanf("%lf%lf", &n, &r);
    double g = 360.00 / (2 * n);
    double x = (r * sin(g * PI / 180.0)) / (1 - sin(g * PI / 180));
    printf("%.7f\n", x);
    return 0;
}
