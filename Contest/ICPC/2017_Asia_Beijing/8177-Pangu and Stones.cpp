//��Ȼ����ϵ�����ľ������ı������⣬�����ǲ���ȷ������������ȷ���������һ����Ȼ��
//�Ҹø�����
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int n, l, r;

int main() {
    while (scanf("%d%d%d", &n, &l, &r) != EOF) {
        priority_queue<int, vector<int>, greater<int> > q;
        for (int i = 0; i < n; ++i) {
            int tmp; scanf("%d", &tmp);
            q.push(tmp);
        }
        int sum = 0;
        int flag = 0;
        while (!q.empty()) {
            if (q.size() < l) { flag = 1; break; }
            int tmp = q.top(); q.pop(); int cnt = 1;
            while (!q.empty() && q.size() + 1 >= l && cnt < r) {
                tmp += q.top(); q.pop(); cnt++;
            }
            if (!q.empty()) q.push(tmp);
            sum += tmp;
        }
        if (flag) puts("0");
        else printf("%d\n", sum);
    }
    return 0;
}
