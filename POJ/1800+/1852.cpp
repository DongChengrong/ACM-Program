#include <stdio.h>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, l;
        int MIN = -1, MAX = -1;
        scanf("%d%d", &l, &n);
        while (n--) {
            int x; scanf("%d", &x);
            MIN = max(MIN, min(x, l - x));
            MAX = max(MAX, max(x, l - x));
        }
        printf("%d %d\n", MIN, MAX);
    }
    return 0;
}
