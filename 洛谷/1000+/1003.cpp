/*
*�����ڱ�����nС��1e4��ֻ��һ������Ҫ������������ǿ��ԴӺ���ǰ�ҵ�һ������ס�õ�
*�ĵ�̺�����û�����-1
*@����:������
*/

#include <stdio.h>
#include <string.h>

#define N 11000

struct Node {
    int a, b, g, k;
}ma[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d%d%d", &ma[i].a, &ma[i].b, &ma[i].g, &ma[i].k);
        }
        int x, y, i;
        scanf("%d%d", &x, &y);
        for (i = n; i >= 1; i--) {
            if (x <= ma[i].a + ma[i].g && x >= ma[i].a &&
                y >= ma[i].b && y <= ma[i].b +ma[i].k) break;
        }
        printf("%d\n", i == 0 ? -1 : i);
    }
    return 0;
}
