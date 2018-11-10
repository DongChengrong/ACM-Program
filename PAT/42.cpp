/*
��Ŀ����:https://pintia.cn/problem-sets/994805342720868352/problems/994805498207911936
������������Ҫ�����˶��е�Ӧ��
��һ��һά�Ķ�������ģ�����д��ڣ�ÿ�������������m��
�ٿ�һ��һά����������洢ÿ�����ڵĽ���ʱ��
ע��ӵ㣺16.59���Խ����¿ͻ�������17.00�Ͳ�������
*/
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

#define N 1100
#define M 25

struct Node {
    int hour, mins;
    Node(int hour = 8, int mins = 0) : hour(hour), mins(mins){}
};

int time[N];
Node f[N];
queue<int> q[N];

int main() {
    int n, m, k, Q;
    scanf("%d%d%d%d", &n, &m, &k, &Q);
    for (int i = 1; i <= k; ++i) {
        int x; scanf("%d", &x);
        int tmp = 1;
        for (int j = 1; j <= n; ++j) {
            if (i <= n * m) {
                if (q[j].size() < q[tmp].size()) tmp = j;
            } else {
                if (q[j].front() < q[tmp].front()) tmp = j;
            }
        }
        time[tmp] += x; q[tmp].push(time[tmp]);
        if (i > m * n) q[tmp].pop();
        if ((time[tmp] - x) >= 9 * 60) f[i].hour = -1;
        else f[i] = Node(time[tmp] / 60 + 8, time[tmp] % 60);
    }
    while (Q--) {
        int x; scanf("%d", &x);
        if (f[x].hour != -1) {
            printf("%02d:%02d\n", f[x].hour, f[x].mins);
        } else {
            puts("Sorry");
        }
    }
    return 0;
}
