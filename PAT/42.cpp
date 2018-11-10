/*
题目链接:https://pintia.cn/problem-sets/994805342720868352/problems/994805498207911936
分析：本题主要考察了队列的应用
开一个一维的队列数组模拟银行窗口，每个串口最多容纳m人
再开一个一维的整形数组存储每个窗口的结束时间
注意坑点：16.59可以接纳新客户，但是17.00就不可以了
*/
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

#define N 1100
#define M 25

struct Node {
    int hour, mins;
    Node(int hour = 8, int mins = 0) : hour(hour), mins(mins){}
};

int time[N];
Node f[N];
queue<int> q[N];

int main() {
    int n, m, k, Q;
    scanf("%d%d%d%d", &n, &m, &k, &Q);
    for (int i = 1; i <= k; ++i) {
        int x; scanf("%d", &x);
        int tmp = 1;
        for (int j = 1; j <= n; ++j) {
            if (i <= n * m) {
                if (q[j].size() < q[tmp].size()) tmp = j;
            } else {
                if (q[j].front() < q[tmp].front()) tmp = j;
            }
        }
        time[tmp] += x; q[tmp].push(time[tmp]);
        if (i > m * n) q[tmp].pop();
        if ((time[tmp] - x) >= 9 * 60) f[i].hour = -1;
        else f[i] = Node(time[tmp] / 60 + 8, time[tmp] % 60);
    }
    while (Q--) {
        int x; scanf("%d", &x);
        if (f[x].hour != -1) {
            printf("%02d:%02d\n", f[x].hour, f[x].mins);
        } else {
            puts("Sorry");
        }
    }
    return 0;
}
