/*
*  UVA 12368
*  ������������ö�٣��ѵ�����check����
*  ����������ʱ��̣ܶ��������Ǳ�����Ԥ����һ�µ�ǰ������������Ƿ�����Ҫ��
* check�����������ģ������ж��Ƿ�ֱ�Ӱ����������
*  ������ֳܷ��������ĺͣ�ע������������Ҳͬ��������һ�����֣���������������
* ������ͼֻдһ�����������жϣ����ʧ����
*/
#include <stdio.h>
#include <string.h>

#define N 1100
#define M 110

int a[N];
int can[N][M];

int have(int x, int y) {  //�ж��Ƿ����y��������
    int tmp = y;
    int cnt[15]; memset(cnt, 0, sizeof(cnt));
    while (tmp) {
        int z = tmp % 10;
        tmp = tmp / 10;
        if (cnt[z]) return 0;
        if (x & (1 << z)) cnt[z]++;
        else return 0;
    }
    return 1;
}

int have2(int x, int y, int z) {  //�ж��Ƿ����y, z��������
    int tmp = y;
    int cnt[15]; memset(cnt, 0, sizeof(cnt));
    while (tmp) {
        int t = tmp % 10;
        tmp = tmp / 10;
        if (cnt[t]) return 0;
        if (x & (1 << t)) cnt[t]++;
        else return 0;
    }
    tmp = z;
    while (tmp) {
        int t = tmp % 10;
        tmp = tmp / 10;
        if (cnt[t]) return 0;
        if (x & (1 << t)) cnt[t]++;
        else return 0;
    }
    return 1;
}

int check(int x, int y) {   //����Ƿ������������
    if (have(x, y)) return 1;
    for (int i = 1; i <= y / 2; ++i) {
        if (i != y - i) {
            if (have2(x, i, y - i)) return 1;
        }
    }
    return 0;
}

void init() {
    for (int i = 1; i < (1 << 10); ++i) {
        for (int j = 1; j <= 100; ++j) {
            can[i][j] = check(i, j);
        }
    }
}

int main() {
    init();  //Ԥ��������İ������
    int n, kase = 0;
    while (scanf("%d", &n) != EOF && n) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        int ans = 0;
        for (int i = 1; i < (1 << 10); ++i) {   //������ö��
            int flag = 1, tmp = 0;
            for (int j = 1; j <= n; ++j) if (!can[i][a[j]]) flag = 0;
            for (int j = 9; j >= 0; --j) if (i & (1 << j)) tmp = tmp * 10 + j;
            if (flag) {
                if (ans == 0 || tmp < ans) ans= tmp;
            }
        }
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
