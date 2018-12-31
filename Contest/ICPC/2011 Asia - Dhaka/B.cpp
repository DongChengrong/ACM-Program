/*
*  UVA 12368
*  分析：二进制枚举，难点在于check函数
*  由于所给的时间很短，所以我们必须现预处理一下当前所购买的蜡烛是否满足要求
* check函数是这样的，首先判断是否直接包含这个数字
*  如果不能分成两个数的和，注意这里两个数也同样不能用一个数字，由于忘记了这里
* 我曾试图只写一个函数进行判断，结果失败了
*/
#include <stdio.h>
#include <string.h>

#define N 1100
#define M 110

int a[N];
int can[N][M];

int have(int x, int y) {  //判断是否包含y所含数字
    int tmp = y;
    int cnt[15]; memset(cnt, 0, sizeof(cnt));
    while (tmp) {
        int z = tmp % 10;
        tmp = tmp / 10;
        if (cnt[z]) return 0;
        if (x & (1 << z)) cnt[z]++;
        else return 0;
    }
    return 1;
}

int have2(int x, int y, int z) {  //判断是否包含y, z所含数字
    int tmp = y;
    int cnt[15]; memset(cnt, 0, sizeof(cnt));
    while (tmp) {
        int t = tmp % 10;
        tmp = tmp / 10;
        if (cnt[t]) return 0;
        if (x & (1 << t)) cnt[t]++;
        else return 0;
    }
    tmp = z;
    while (tmp) {
        int t = tmp % 10;
        tmp = tmp / 10;
        if (cnt[t]) return 0;
        if (x & (1 << t)) cnt[t]++;
        else return 0;
    }
    return 1;
}

int check(int x, int y) {   //检查是否可以满足需求
    if (have(x, y)) return 1;
    for (int i = 1; i <= y / 2; ++i) {
        if (i != y - i) {
            if (have2(x, i, y - i)) return 1;
        }
    }
    return 0;
}

void init() {
    for (int i = 1; i < (1 << 10); ++i) {
        for (int j = 1; j <= 100; ++j) {
            can[i][j] = check(i, j);
        }
    }
}

int main() {
    init();  //预处理蜡烛的包含情况
    int n, kase = 0;
    while (scanf("%d", &n) != EOF && n) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        int ans = 0;
        for (int i = 1; i < (1 << 10); ++i) {   //二进制枚举
            int flag = 1, tmp = 0;
            for (int j = 1; j <= n; ++j) if (!can[i][a[j]]) flag = 0;
            for (int j = 9; j >= 0; --j) if (i & (1 << j)) tmp = tmp * 10 + j;
            if (flag) {
                if (ans == 0 || tmp < ans) ans= tmp;
            }
        }
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
