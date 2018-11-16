/*
*��������Ϊ�ǰ������루��y��������룩��������ֱ������״����Ϳ�����
*ע����������0,0��������Ԥ����Ļ���T
*
**/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 15100
#define M 32010

int n;
int c[M], vis[N];

void add(int x, int d) {
    while (x < M) {
        c[x] = c[x] + d;
        x += x & (-x);
    }
}

int sum(int x) {
    int res = 0;
    while (x) {
        res += c[x];
        x -= x & (-x);
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) vis[i] = 0;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; ++i) {
        int x, y, val;
        scanf("%d%d", &x, &y); ++x;
        val = sum(x); ++vis[val]; add(x, 1);
    }
    for (int i = 0; i < n; ++i) printf("%d\n", vis[i]);
    return 0;
}
