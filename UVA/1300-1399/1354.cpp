#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 10

struct Node {  //实用的数据结构
    double left, right;
    Node():left(0), right(0){}
};

//用到的数据定义
int n, vis[1 << N];
double r, w[N];
vector<Node> tree[1 << N];
double sum[1 << N];

void dfs(int subset) {
    if (vis[subset]) return;
    vis[subset] = 1;
    int have_child = 0;
    for (int left = (subset - 1) & subset; left; left = (left - 1) & subset) {   //一种精巧的枚举方法
        have_child = 1;
        int right = left ^ subset;  //右孩子子集
        double dis1 = sum[right] / sum[subset];   //按比例,杠杆原理
        double dis2 = sum[left] / sum[subset];
        dfs(left); dfs(right);
        for (int i = 0; i < tree[left].size(); ++i) {
            for (int j = 0; j < tree[right].size(); ++j) {
                Node tmp;
                tmp.left = max(tree[left][i].left + dis1, tree[right][j].left - dis2);
                tmp.right = max(tree[right][j].right + dis2, tree[left][i].right - dis1);
                if (tmp.left + tmp.right < r) tree[subset].push_back(tmp);
            }
        }
    }
    if (!have_child) tree[subset].push_back(Node());  //非常重要
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lf", &r); scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%lf", &w[i]);
        for (int i = 0; i < (1 << n); ++i) {   //预处理
            sum[i] = 0;
            tree[i].clear();
            for (int j = 0; j < n; ++j) {    //完美的预处理
                if (i & (1 << j)) sum[i] += w[j];
            }
        }
        double ans = -1;
        int root = (1 << n) - 1;
        memset(vis, 0, sizeof(vis));
        dfs(root);
        int sz = tree[root].size();
        for (int i = 0; i < sz; ++i) {  //枚举子集寻找最优解
            ans = max(tree[root][i].left + tree[root][i].right, ans);
        }
        printf("%.10f\n", ans);
    }
    return 0;
}
