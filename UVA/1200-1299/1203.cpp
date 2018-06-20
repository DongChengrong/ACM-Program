#include <stdio.h>
#include <queue>
using namespace std;

#define N 20

char cmd[N];

struct Node {
    int id, t, p;
    Node() {}
    Node (int id, int t, int p) {
        this->id = id;
        this->t = t;
        this->p = p;
    }
    bool operator < (const Node & a) const {
        return p > a.p || (p == a.p && id > a.id);
    }
};

int main() {
    int n;
    priority_queue<Node> que;
    while (scanf("%s",cmd) == 1) {
        int id, t;
        if (cmd[0] == '#') break;
        scanf("%d%d", &id, &t);
        que.push(Node(id, t, t));
    }
    scanf("%d",&n);
    while (n--) {
        Node u = que.top(); que.pop();
        printf("%d\n",u.id);
        que.push(Node(u.id, u.t, u.p + u.t));
    }
    return 0;
}
