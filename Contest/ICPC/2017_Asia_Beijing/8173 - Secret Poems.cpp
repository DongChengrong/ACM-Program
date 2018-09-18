/*
*Ä£Äâ
*/
#include <stdio.h>
#include <string.h>

#define N 110

int n;
char order[N * N];
char old[N][N], New[N][N];

void read() {
    int i, j, cnt;
    int l = 0, r = 1, f = 0, d = 0;
    i = j = cnt = 0;
    while (1) {
        //printf("%d %d %d\n", i, j, cnt);
        order[cnt] = old[i][j];

        if (l) {
            if (j - 1 >= 0 && i + 1 < n) j = j - 1, i = i + 1, cnt = cnt + 1;
            else l = 0, d = 1;
        } else if (r) {
            if (j + 1 < n) j = j + 1, r = 0, l = 1, cnt = cnt + 1;
            else r = 0, l = 1, i += 1, cnt = cnt + 1;
        } else if (f) {
            if (i - 1 >= 0 && j + 1 < n) i = i - 1, j = j + 1, cnt = cnt + 1;
            else f = 0, r = 1;
        } else if (d) {
            if (i + 1 < n) i = i + 1, d = 0, f = 1, cnt = cnt + 1;
            else d = 0, f = 1, j = j + 1, cnt = cnt + 1;
        }
        if (cnt == n * n) break;
    }
    order[cnt + 1] = '\0';
}

void write() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            New[i][j] = '0';
        }
    }

    int i, j, cnt;
    int l = 0, r = 1, f = 0, d = 0;
    i = j = cnt = 0;
    while (1) {
        New[i][j] = order[cnt];

        if (l) {
            if (j - 1 >= 0 && New[i][j - 1] == '0') j = j - 1, cnt = cnt + 1;
            else l = 0, f = 1;
        } else if (r) {
            if (j + 1 < n && New[i][j + 1] == '0') j = j + 1, cnt = cnt + 1;
            else r = 0, d = 1;
        } else if (f) {
            if (i - 1 >= 0 && New[i - 1][j] == '0') i = i - 1, cnt = cnt + 1;
            else f = 0, r = 1;
        } else if (d) {
            if (i + 1 < n && New[i + 1][j] == '0') i = i + 1, cnt = cnt + 1;
            else d = 0, l = 1;
        }
        if (cnt == n * n - 1) break;
    }
    New[i][j] = order[cnt];
}

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) scanf("%s", old[i]);
        read(); write();
        //puts(order);
        for (int i = 0; i < n; ++i) {
            New[i][n] = '\0'; puts(New[i]);
        }
    }
    return 0;
}
