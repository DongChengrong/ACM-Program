#include <stdio.h>
#include <queue>
using namespace std;

int main() {
    int n;
    while (scanf("%d",&n) == 1) {

        priority_queue<int, vector<int>, greater<int> > que;

        while (n--) {
            int x;
            scanf("%d",&x);
            que.push(x);
        }

        int ans = 0;
        while (que.size() > 1) {
            int x = que.top(); que.pop();
            int y = que.top(); que.pop();
            que.push(x +y);
            ans += x + y;
        }

        printf("%d\n",ans);
    }
    return 0;
}
