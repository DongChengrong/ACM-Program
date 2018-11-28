/*
*题目链接：https://pintia.cn/problem-sets/994805342720868352/problems/994805491530579968
*分析：开数组，跑模拟
*
**/
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

#define N 11000
#define M 11000

int n, m;

struct Node {
    int time, p;
    bool operator < (const Node &u) const{
        return time < u.time;
    }
};

Node a[N];
int q[N];

int main() {
    int i, tot = 0, num = 0;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; ++i) {
        int h, m, s, p;
        scanf("%d:%d:%d %d", &h, &m, &s, &p);
        int time = h * 3600 + m * 60 + s;
        a[i] = (Node){time, p};
    }
    sort(a, a + n);
    for (i = 0; i < n; ++i) {
        int k = 0;
        if (a[i].time >= 17 * 3600) break; ++num;
        if (a[i].time < 8 * 3600) tot = tot + 8 * 3600 - a[i].time, a[i].time = 8 * 3600;
        for (int j = 1; j < m; ++j) {
            if (q[j] < q[k]) {
                k = j;
            }
        }
        if (q[k] < a[i].time) {
            q[k] = a[i].time + a[i].p * 60;
        } else {
            tot += q[k] - a[i].time;
            q[k] += a[i].p * 60;
        }
    }
    printf("%.1f\n", ((float)tot / (float)(num)) / 60.00);
    return 0;
}
