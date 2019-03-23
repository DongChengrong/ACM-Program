//ÌâÄ¿Á´½Ó£ºhttp://118.190.20.162/view.page?gpid=T67
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;

struct Node {
    int id, value;
};

bool judge(int x) {
    if (x % 10 == k) return true;
    if (x % k == 0) return true;
    return false;
}

int main() {
    queue<Node> q;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) q.push((Node){i, i});
    while (q.size() > 1) {
        Node u = q.front(); q.pop();
        if (!judge(u.value)) {
            q.push((Node){u.id, u.value + q.size() + 1});
        }
    }
    Node u = q.front();
    printf("%d\n", u.id);
    return 0;
}
