#include <stdio.h>
#include <string.h>

#define N 110000

char s[N];

int main() {
    int n;
    while (scanf("%d",&n) == 1) {
        scanf("%s",s);
        int cnt = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'x') cnt++;
            else {
                if (cnt > 2) sum += cnt - 2;
                cnt = 0;
            }
        }
        if (cnt > 2) sum += cnt - 2;
        printf("%d\n", sum);
    }
    return 0;
}