#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define N 110

int a[N];

int main() {
    while (scanf("%d%d%d", &a[0], &a[1], &a[2]) != EOF) {
        int cost = 0;
        sort(a, a + 3);
        cost = abs(a[1] - a[0]) + abs(a[2] - a[1]);
        printf("%d\n", cost);
    }
    return 0;
}
