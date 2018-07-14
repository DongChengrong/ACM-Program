//Ë®ÌâÒ»Ã¶
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n, l;
    while (scanf("%d%d", &l, &n) != EOF) {
        int MAX = 0, MIN = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            MIN = max(MIN, min(x, l - x + 1));
            MAX = max(MAX, max(x, l - x + 1));
        }
        printf("%d %d\n", MIN, MAX);
    }
    return 0;
}
