/*
题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=6411
题目来源：2018百度之星复赛
题目类型：并查集 + 排序 + 位运算
题目分析：观察易知，仅有同属于一个集合的节点f(i, j) = 1，所以可以使用并查集将集合分类
将不同集合的元素放入一个变长数组中去，然后对该数组排序，排序的关键字是v值从小到大，可以
确保对于节点i, j (j < i) max(v[i], v[j]) = v[i], 由此可以得出f(i, j) * max(v[i], v[j]) = v[i]
(i,j属于同一集合且排序后j < i). 接下需要处理(v[i] & v[j])，可以模拟位运算。
先将样例中具有节点1的集合的所有的元素v值按二进制表出如下：
      3 : 0  0  1  1
      4 : 0  1  0  0
      9 : 1  0  0  1
      9 : 1  0  0  1
我们对每一位进行枚举，若当前枚举元素v值在第j位上为1，且前面的元素中贡献了两个1
则我们可以认为前i的元素(v[i] & v[j])之和为2 * (1 << j)
故我们最终得到公式if (tmp & 1)  sum += v[i] * (1 << j) * bit[j]
(bit[j]代表第j位在前面共出现了几个1, tmp代表当前节点的v值)
注意要及时求余来确保答案不会溢出
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 100100
#define Mod 1000000007

typedef long long ll;

struct Node {
    int id;
    ll v;
    bool operator < (const Node &u) const {
        return this->v < u.v || (this->v == u.v && this->id < u.id);
    }
};

int pa[N], vis[N];
ll v[N];
vector<Node> vec[N];

void init(int n) {
    memset(vis, 0, sizeof(int) * (n + 10));
    for (int i = 0; i <= n; ++i) {
        pa[i] = i;
        vec[i].clear();
    }
}

int findset(int x) {
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

void _union(int x, int y) {
    x = findset(x);
    y = findset(y);
    if (x != y) {
        pa[x] = y;
        findset(x);
    }
}

void compute(int root, ll &sum) {   //对于每一个集合计算权值
    int bit[35], i = 0;  //表示每位
    memset(bit, 0, sizeof(bit));
    sort(vec[root].begin(), vec[root].end());
    while (vec[root][0].v) {
        if (vec[root][0].v & 1) ++bit[i];
        i = i + 1;
        vec[root][0].v >>= 1;
    }
    for (i = 1; i < vec[root].size(); ++i) {
        ll tmp = (ll)vec[root][i].v;
        for (int j = 0; j < 35; ++j) {
            if (bit[j] && ((tmp >> j) & 1)) {
                sum += (((1ll) << j) * (((ll)bit[j] * tmp) % Mod)) % Mod;
                sum = sum % Mod;
            }
            if ((tmp >> j) & 1) bit[j]++;
        }
    }
    vis[root] = 1;
}

int main() {
    int T, n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        init(n);
        for (int i = 1; i <= n; ++i) scanf("%lld", &v[i]);
        for (int i = 0; i < m; ++i) {  //读入边并建立并查集
            int u, v;
            scanf("%d %d", &u, &v);
            _union(u, v);
        }
        for (int i = 1; i <= n; ++i) {   //将节点分成数个集合
            int pa = findset(i);
            vec[pa].push_back((Node){i, v[i]});
        }
        ll sum = 0;  //最终答案
        for (int i = 1; i <= n; ++i) {  //计算过程，对于每个集合调用compute函数
            int root = findset(i);
            if (vis[root]) continue;
            else compute(root, sum);
        }
        printf("%lld\n", sum);
    }
    return 0;
}
