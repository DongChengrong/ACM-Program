/*
*   UVA466
*分析：因为可能相同的组合有限
*所以此题用枚举的方式进行判断
**/
#include <stdio.h>
#include <string.h>

#define N 55

void print(char a[N][N], int n);
void rotation(char a[N][N], char b[N][N], int n);
int cmp(char a[N][N], char b[N][N], int n);

void print(char a[N][N], int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%c", a[i][j]);
        }
        puts("");
    }
    puts("");
}

void rotation(char a[N][N], char b[N][N], int n) {
    for (int i = n; i >= 1; --i) {
        for (int j = n; j >= 1; --j) {
            b[i][n - j + 1] = a[j][i];
        }
    }
}

int cmp(char a[N][N], char b[N][N], int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] != b[i][j]) return 0;
        }
    }
    return 1;
}

void reflection(char a[N][N], char b[N][N], int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            b[n - i + 1][j] = a[i][j];
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, kase = 0;
    while (scanf("%d", &n) != EOF) {
        printf("Pattern %d was ", ++kase);
        char a[N][N], b[N][N], c[N][N], d[N][N];
        for (int i = 1; i <= n; ++i) {
            scanf("%s %s", a[i] + 1, b[i] + 1);
        }
        if (cmp(a, b, n)) {
            puts("preserved.");
            continue;
        }
        memcpy(c, a, sizeof(a));
        int i = 1;
        for(i = 1; i <= 3; ++i) {
            rotation(c, d, n);
            if (cmp(d, b, n)) {
                printf("rotated %d degrees.\n", i * 90);
                break;
            }
            memcpy(c, d, sizeof(d));
        }
        if (i <= 3) continue;
        reflection(a, c, n);
        if (cmp(c, b, n)) {
            puts("reflected vertically.");
            continue;
        }
        for (i = 1; i <= 3; ++i) {
            rotation(c, d, n);
            if (cmp(d, b, n)) {
                printf("reflected vertically and rotated %d degrees.\n", i * 90);
                break;
            }
            memcpy(c, d, sizeof(c));
        }
        if (i >= 4) printf("improperly transformed.\n");
    }
    return 0;
}
