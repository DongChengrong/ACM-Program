#include <stdio.h>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

#define INF 2200000000

typedef long long ll;

struct Node {
    ll val;
    int step;
};

map<ll, int> ma1;
map<ll, int> ma;

int bfs(ll x) {
    ma1.clear();
    if (ma[x]) return ma[x];
    Node u = (Node){x, 0};
    queue<Node> q;
    q.push(u);
    ma1[x] = 1;
    while (!q.empty()) {
        Node v = q.front();
        q.pop();
        if (v.val == 1) {
            return ma[v.val] = v.step;
        } else {
            ll a = v.val * 2;
            if (a < INF && !ma1[a]) {
                q.push((Node){a, v.step + 1});
                ma1[a] = 1;
            }
            ll b = v.val / 6;
            if (v.val % 6 == 0 && !ma1[b]) {
                q.push((Node){b, v.step + 1});
                ma1[b] = 1;
            }
        }
    }
    return ma[x] = -1;
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--) {
        ll x;
        scanf("%I64d", &x);
        printf("%d\n", bfs(x));
    }
    return 0;
}
