//ÌâÄ¿Á´½Ó£ºhttps://www.nowcoder.com/pat/6/problem/4049
#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 110

int a[N];

int main() {
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < 10; ++i) if (a[i]) {
        printf("%d", i); a[i]--; break;
    }
    for (int i = 0; i < 10; ++i) {
        if (a[i]) {
            for (int j = 0; j < a[i]; ++j)
                printf("%d", i);
        }
    }
    puts("");
    return 0;
}
