/*
*题目链接：https://pintia.cn/problem-sets/994805342720868352/problems/994805343463260160
*分析：直接映射一下，没出现的标记为，出现过标记为1
*初始化结果res为1，若果出现的数等于res，res++
*j坑点： 有大于1e5的数据出现，但实际上res的范围在1e5内
*/
#include <stdio.h>
#include <string.h>

#define N 110000

int a[N];

int main() {
    int n, res = 1;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; ++i) {
        int tmp; scanf("%d", &tmp);
        if (tmp <= 0) continue;
        if (tmp >= N) continue;
        a[tmp] = 1;
        if (tmp == res) {
            while (a[res]) res++;
        }
    }
    printf("%d\n", res);
    return 0;
}
