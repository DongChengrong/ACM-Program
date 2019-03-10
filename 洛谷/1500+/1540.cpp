#include <stdio.h>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF) {
        int res = 0;
        deque<int> q;
        unordered_map<int, int> ma;
        for (int i = 0; i < n; ++i) {
            int x; scanf("%d", &x);
            if (ma[x] == 0) {
                //printf("%d %d\n", x, ma[x]);
                q.push_back(x);
                if (q.size() > m) {
                    int y = q.front();
                    q.pop_front();
                    ma[y] = 0;
                }
                ma[x] = 1; ++res;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
