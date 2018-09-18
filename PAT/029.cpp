/*
*��Ŀ���ӣ�https://pintia.cn/problem-sets/994805342720868352/problems/994805509540921344
*ע�⣺
*1��ָ����˺�����ָ���ᵽ��2000
*2���е�ָ�����ܻᱻһ��һ������ϵ������
*/
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

#define N 2200

struct Node {
    int e;
    double c;
};

double C[N];

int main() {
    int n, e;
    double c;
    vector<Node> vec;
    for (int i = 0; i < N; ++i) C[i] = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%lf", &e, &c);
        vec.push_back((Node){e, c});
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d%lf", &e, &c);
        for (int j = 0; j < vec.size(); ++j) {
            int dd = vec[j].e + e;
            double cc = vec[j].c * c;
            C[dd] += cc;
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; ++i) if (C[i] != 0) cnt++;
    printf("%d", cnt);
    for (int i = N - 1; i >= 0; --i) {
        if (C[i] != 0) {
            printf(" %d %.1f", i, C[i]);
        }
    }
    return 0;
}
