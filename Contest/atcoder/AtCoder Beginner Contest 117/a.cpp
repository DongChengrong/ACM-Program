#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    double t, x;
    while (scanf("%lf%lf", &t, &x) != EOF) {
        printf("%.10f\n", t / x);
    }
    return 0;
}
