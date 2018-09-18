/*
*·ÖÎö£º
*
*
*
**/
#include <stdio.h>
#include <string.h>

#define N 110000

int a[N];

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        int l, r;
        int n, sum = -1, MAX = -1, len = -1;
        scanf("%d", &n);
        for (int i = 1; i <= n - 1; ++i) scanf("%d", &a[i]);
        int i = 1, j = 1;
        a[n] = -10000000;
        while (i <= n + 1) {
            //printf("%d %d %d\n", j, i, sum);
            if (sum > MAX) {
                //printf("%d %d %d\n", j, i, sum);
                MAX = sum;
                l = j; r = i; len = (i - j);
            } else if (sum == MAX && (i - j) > len){
                l = j; r = i; len = (i - j);
            }
            if (sum < 0) {
                sum = a[i]; j = i; ++i;
            } else {
                sum += a[i++];
            }
        }
        if (MAX > 0) printf("The nicest part of route 1 is between stops %d and %d\n", l, r);
        else printf("Route %d has no nice parts\n", kase);
    }
    return 0;
}
