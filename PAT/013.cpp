//ÌâÄ¿Á´½Ó£ºhttps://www.nowcoder.com/pat/6/problem/4044
#include <stdio.h>
#include <string.h>

int v1[5],v2[5];
char s[] = "BCJ";

int id(char c) {
    if (c == 'C') return 0;
    if (c == 'J') return 1;
    if (c == 'B') return 2;
    return -1;
}

int main() {
    int T, a1, a2, a3;
    scanf("%d", &T); getchar();
    a1 = a2 = a3 = 0;
    memset(v1, 0, sizeof(v1));
    memset(v2, 0, sizeof(v2));
    while (T--) {
        int t1, t2;
        char u, v;
        scanf("%c %c", &u, &v); getchar();
        t1 = id(u); t2 = id(v);
        v1[t1]++; v2[t2]++;
        if (t2 == t1) a3++;
        else if (t2 - t1 == 1 || t1 - t2 == 2) a1++;
        else a2++;

    }
    printf("%d %d %d\n", a1, a3, a2);
    printf("%d %d %d\n", a2, a3, a1);
    int i = 0, j;
    for (j = 1; j < 2; ++j) if (v2[j] > v2[i]) i = j;
    printf("%c ",s[i]);
    i = 0;
    for (j = 1; j < 2; ++j) if (v1[j] > v1[i]) i = j;
    printf("%c\n", s[i]);
    return 0;
}
/*
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
*/
