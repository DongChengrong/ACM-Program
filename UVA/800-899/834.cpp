#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int b, k;
    while (scanf("%d%d", &b, &k) == 2) {
        int cnt = 1;
        printf("[");
        printf("%d", b / k);
        b = b % k;
        swap(b, k);
        while (b % k) {
            if (cnt == 1) printf(";");
            else printf(",");
            cnt = 0;
            printf("%d", b / k);
            b = b % k;
            swap(b, k);
        }
        printf("%c%d]\n", cnt == 1 ? ';' : ',', b);
    }
    return 0;
}
