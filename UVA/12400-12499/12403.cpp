/*
*   UVA  12403
*  题目链接：https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=279&page=show_problem&problem=3834
*  分析：基本的模拟题，如果硬要说(实际上没有)有什么难点的话，那就只能是判断两种指令了
*  我们知道c语言的标准库中提供了一个比较函数strcmp用于比较两个字符串是否相等，所以我们可以
* 使用这个函数来判别我们接收到的是那条指令；但实际上我们完全没有必要采用这个O(N)的函数来
* 甄别捐款和报告这两个指令，容易注意到donation和report的首字母不一致，所以我们只需要比较这个
* 字符串的首字母就够了，时间复杂度仅为O(1)
*/
#include <stdio.h>

typedef long long ll;

#define N 15

char s[N];

int main() {
    int T;
    ll money = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        if (s[0] == 'd') {
            ll x; scanf("%lld", &x); money += x;
        } else {
            printf("%lld\n", money);
        }
    }
    return 0;
}
