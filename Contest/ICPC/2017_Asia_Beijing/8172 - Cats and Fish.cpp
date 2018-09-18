/*
*分析：采用优先队列模拟
*我们设一个结构体，里面有结束时间和一条鱼花费的时间
*开始时，只要还有鱼我们就把他加入优先队列当中，然后鱼数-1
*当队列不为空时，我们取出栈顶元素，如果结束时间等于x，直接pop
*如果结束时间小于x，先pop一下，然后判断鱼数是否大于0，大于0的话在给他一条
*如果结束时间大于x，跳出循环
****/
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

#define N 11000

struct Node {
    int cur, t;
    bool operator < (const Node &u) const {
        if (this->cur != u.cur) return this->cur > u.cur;
        else return this->t > u.t;
    }
};

int a[N];

int main() {
    int m, n, x;
    while (scanf("%d%d%d", &m, &n, &x) != EOF) {
        if (!x) { printf("%d 0\n", m); continue; }
        priority_queue<Node> q;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        for (int i = 0; i < n; ++i) {
            if (m) { q.push((Node){a[i], a[i]}); m--; }
            else break;
        }
        while (!q.empty()) {
            Node u = q.top();
            if (u.cur == x)  { q.pop(); }
            else if (u.cur < x) {
                q.pop();
                if (m) {
                    u.cur += u.t; m--;
                    q.push(u);
                }
            } else break;
        }
        if (q.size() >= m) m = 0;
        printf("%d %d\n", m, q.size());
    }
    return 0;
}
