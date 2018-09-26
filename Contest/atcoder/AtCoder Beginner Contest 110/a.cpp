#include <stdio.h>
#include <algorithm>

using namespace std;

int a[5];

int main() {
    while (scanf("%d%d%d", &a[0], &a[1], &a[2]) != EOF) {
        sort(a, a + 3);
        printf("%d\n", a[2] * 10 + a[1] + a[0]);
    }
    return 0;
}
