/*
*�������������ȶ���ģ��
*������һ���ṹ�壬�����н���ʱ���һ���㻨�ѵ�ʱ��
*��ʼʱ��ֻҪ���������ǾͰ����������ȶ��е��У�Ȼ������-1
*�����в�Ϊ��ʱ������ȡ��ջ��Ԫ�أ��������ʱ�����x��ֱ��pop
*�������ʱ��С��x����popһ�£�Ȼ���ж������Ƿ����0������0�Ļ��ڸ���һ��
*�������ʱ�����x������ѭ��
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
