#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 110

int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    do {
        int x = a[0] * 100 + a[1] * 10 + a[2];
        int y = a[3] * 100 + a[4] * 10 + a[5];
        int z = a[6] * 100 + a[7] * 10 + a[8];
        if (x * 2 == y && x * 3 == z) printf("%d %d %d\n", x, y, z);
    } while (next_permutation(a, a + 9));
    return 0;
}
