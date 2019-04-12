#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 11000

int n;
int a[N];
int day = 0, need = -1, cur = 0;

void _move() {
    need = a[++cur]; day++;
    while (cur <= n) {
        if (cur == n || cur == need) break;
        need = max(need, a[++cur]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    while (1) {
        _move();
        if (cur == n) break;
    }
    printf("%d\n", day);
    return 0;
}
