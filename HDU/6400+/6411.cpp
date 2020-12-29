/*
��Ŀ���ӣ�http://acm.hdu.edu.cn/showproblem.php?pid=6411
��Ŀ��Դ��2018�ٶ�֮�Ǹ���
��Ŀ���ͣ����鼯 + ���� + λ����
��Ŀ�������۲���֪������ͬ����һ�����ϵĽڵ�f(i, j) = 1�����Կ���ʹ�ò��鼯�����Ϸ���
����ͬ���ϵ�Ԫ�ط���һ���䳤������ȥ��Ȼ��Ը�������������Ĺؼ�����vֵ��С���󣬿���
ȷ�����ڽڵ�i, j (j < i) max(v[i], v[j]) = v[i], �ɴ˿��Եó�f(i, j) * max(v[i], v[j]) = v[i]
(i,j����ͬһ�����������j < i). ������Ҫ����(v[i] & v[j])������ģ��λ���㡣
�Ƚ������о��нڵ�1�ļ��ϵ����е�Ԫ��vֵ�������Ʊ�����£�
      3 : 0  0  1  1
      4 : 0  1  0  0
      9 : 1  0  0  1
      9 : 1  0  0  1
���Ƕ�ÿһλ����ö�٣�����ǰö��Ԫ��vֵ�ڵ�jλ��Ϊ1����ǰ���Ԫ���й���������1
�����ǿ�����Ϊǰi��Ԫ��(v[i] & v[j])֮��Ϊ2 * (1 << j)
���������յõ���ʽif (tmp & 1)  sum += v[i] * (1 << j) * bit[j]
(bit[j]�����jλ��ǰ�湲�����˼���1, tmp����ǰ�ڵ��vֵ)
ע��Ҫ��ʱ������ȷ���𰸲������
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

void compute(int root, ll &sum) {   //����ÿһ�����ϼ���Ȩֵ
    int bit[35], i = 0;  //��ʾÿλ
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
        for (int i = 0; i < m; ++i) {  //����߲��������鼯
            int u, v;
            scanf("%d %d", &u, &v);
            _union(u, v);
        }
        for (int i = 1; i <= n; ++i) {   //���ڵ�ֳ���������
            int pa = findset(i);
            vec[pa].push_back((Node){i, v[i]});
        }
        ll sum = 0;  //���մ�
        for (int i = 1; i <= n; ++i) {  //������̣�����ÿ�����ϵ���compute����
            int root = findset(i);
            if (vis[root]) continue;
            else compute(root, sum);
        }
        printf("%lld\n", sum);
    }
    return 0;
}
