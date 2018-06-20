#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

#define N 1100
#define _for(i, a, b) for (int i = (a); i < (b); ++i)

typedef long long ll;

int n;
ll a[N][N];

struct Node {
    ll num, b;
    Node() {}
    Node(ll num, ll b) {
        this->num = num;
        this->b = b;
    }
    bool operator < (const Node &a) const {
        return num > a.num;
    }
};

void merge(ll *a, ll *b, ll *c, int n) {
    priority_queue<Node> que;
    _for (i, 0, n) que.push(Node(a[i] + b[0], 0));
    _for (i, 0, n) {
        Node u = que.top(); que.pop();
        c[i] = u.num;
        que.push(Node(u.num - b[u.b] + b[u.b + 1], u.b + 1));
    }
}

int main() {
    while (scanf("%d",&n) != EOF) {
        _for (i, 0, n) {
            _for (j, 0, n) scanf("%lld",&a[i][j]);
            sort(a[i], a[i] + n);
        }
        _for (i, 1, n) merge(a[0], a[i], a[0], n);
        _for (i, 0, n) printf("%lld%c",a[0][i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}
