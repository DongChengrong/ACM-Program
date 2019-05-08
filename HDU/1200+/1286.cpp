#include <stdio.h>
#include <math.h>

#define N 32768

int phi[N];

void phi_table() {
    for (int i = 2; i < N; ++i) phi[i] = 0;
    phi[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!phi[i]) {
            for (int j = i; j < N; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

int main() {
    phi_table();
    int T; scanf("%d", &T);
    while(T--) {
        int n; scanf("%d", &n); printf("%d\n", phi[n]);
    }
    return 0;
}
