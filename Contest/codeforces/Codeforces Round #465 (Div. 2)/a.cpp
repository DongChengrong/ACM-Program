#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int res = 1;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                ++res;
                if (i != n / i) ++res;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
