#include <stdio.h>

void get(int &s1) {
    int x;
    scanf("%d",&x); s1 += x * 60 * 60;
    scanf("%d",&x); s1 += x * 60;
    scanf("%d",&x); s1 += x;
}

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        int s1 = 0, s2 = 0;
        get(s1); get(s2);
        s1 += s2;
        printf("%d %d %d\n", s1 / 3600, (s1 % 3600) / 60, (s1 % 3600 % 60 ));
    }
    return 0;
}
