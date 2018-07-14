/*
*     UVA 818
*����������ˮ����
*
*������һЩ������ͬ�������
*
*Ҫ��
*    ����һ��������������Ҫ���ͼ
*    һ�������л�
*    ��������һ��ֱ��
*    �������нڵ�Ҫ����һ��
*
*���������ǽ�����ѡ��һ���ڵ������Ӳ�ͬ���߶�
*    ÿ������ѡ��һ���ڵ�ʱ���ýڵ��������ڵ�����ӶϿ�
*    ��ʱ���ڵ�����������߶�
*
*�ⷨ��λ���㱩��ö�ٽڵ�״̬(ѡ�л�δѡ��)
*
*ע�⣺�������ݼ�ǿ��ע�⴦����ͬ��
*
*PS����Ϊ�����ʼû��ע�⵽��ͬ�ߵ����������
*  ����������ʵ������һ�ֱȽϷѾ��Ľⷨ
*
*�������ݣ�

Sample Input
2 1 2 1 2 -1 -1
2 1 2 2 1 1 2 2 1 -1 -1
3 1 2 -1 -1
0

Sample output
Set 1: Minimum links to open is 0
Set 2: Minimum links to open is 0
Set 3: Minimum links to open is 1
*/


#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#define N 30
#define INF 0x3f3f3f3f
#define _for(i,a,b) for (int i = (a); i < (b); ++i)

int n, cnt;
int vis[N], ma[N][N];
vector<int> G[N];

void init() {
    int u, v;
    memset(ma, 0, sizeof(ma));
    _for (i, 0, N) G[i].clear();
    while (scanf("%d%d", &u, &v) != EOF && u != -1) {
        if (!ma[u][v]) {
            G[u].push_back(v); G[v].push_back(u);
            ma[u][v] = 1; ma[v][u] = 1;
        }
    }
}

int num(int x) {
    return x == 0 ? 0 : num(x / 2) + (x & 1);
}

//����Ƿ��л�
bool dfs(int i, int s, int f) {
    if (vis[i]) return true;

    vis[i] = 1;

    _for (j, 0, G[i].size()) {
        int v = G[i][j];
        if (v == f) continue;
        if ((1 << (v - 1) & s)) continue;
        if (dfs(v, s, i)) return true;
    }

    return false;
}

bool check(int s) {

    //����Ƿ�����Ƿ�������������֧
    for (int i = 1; i <= n; ++i) {

        int res = 0;
        if ((1 << (i - 1)) & s) continue;

        _for (j, 0, G[i].size()) {
            int v = G[i][j];
            if ((1 << (v - 1)) & s) continue;
            ++res;
        }

        if (res > 2) return true;
    }

    //����Ƿ񹹳ɻ�
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i) {
        if ((1 << (i - 1)) & s) continue;
        if (vis[i]) continue;

        ++cnt;

        if (dfs(i, s, -1)) {
            return true;
        }
    }

    return false;
}

int slove() {
    int ans = INF;
    _for (i, 0, (1 << n)) {
        if (!check(i)) {
            if (num(i) >= cnt - 1) {
                ans = min(ans, num(i));
            }
        }
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    int kase = 0;
    while (scanf("%d", &n) == 1 && n) {
        init();
        printf("Set %d: Minimum links to open is %d\n", ++kase, slove());
    }
    return 0;
}
