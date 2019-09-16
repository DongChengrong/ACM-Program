#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    int n, k, T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        if (n == 0) puts("Bob");
        else if (n == 1 || n == 2 || n == k) puts("Alice");
        else if (n < k) {
            if (n % 3 == 0) puts("Bob"); else puts("Alice");
        } else {
            if (k % 3 == 0) {
                if (k == 3) { if (n % 4 == 0) puts("Bob"); else puts("Alice"); }
                else if ((n - (n / (k + 1)) * (k + 1)) % 3 == 0 && (n + 1) % (k + 1) != 0) puts("Bob");
                else puts("Alice");
            } else {
                if (n % 3 == 0) puts("Bob"); else puts("Alice");
            }
        }
    }
    return 0;
}

