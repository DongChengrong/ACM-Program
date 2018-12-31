#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 10

struct Node {  //ʵ�õ����ݽṹ
    double left, right;
    Node():left(0), right(0){}
};

//�õ������ݶ���
int n, vis[1 << N];
double r, w[N];
vector<Node> tree[1 << N];
double sum[1 << N];

void dfs(int subset) {
    if (vis[subset]) return;
    vis[subset] = 1;
    int have_child = 0;
    for (int left = (subset - 1) & subset; left; left = (left - 1) & subset) {   //һ�־��ɵ�ö�ٷ���
        have_child = 1;
        int right = left ^ subset;  //�Һ����Ӽ�
        double dis1 = sum[right] / sum[subset];   //������,�ܸ�ԭ��
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
    if (!have_child) tree[subset].push_back(Node());  //�ǳ���Ҫ
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lf", &r); scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%lf", &w[i]);
        for (int i = 0; i < (1 << n); ++i) {   //Ԥ����
            sum[i] = 0;
            tree[i].clear();
            for (int j = 0; j < n; ++j) {    //������Ԥ����
                if (i & (1 << j)) sum[i] += w[j];
            }
        }
        double ans = -1;
        int root = (1 << n) - 1;
        memset(vis, 0, sizeof(vis));
        dfs(root);
        int sz = tree[root].size();
        for (int i = 0; i < sz; ++i) {  //ö���Ӽ�Ѱ�����Ž�
            ans = max(tree[root][i].left + tree[root][i].right, ans);
        }
        printf("%.10f\n", ans);
    }
    return 0;
}
