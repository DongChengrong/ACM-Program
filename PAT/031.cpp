/*
*��Ŀ���ӣ�https://pintia.cn/problem-sets/994805342720868352/problems/994805343463260160
*������ֱ��ӳ��һ�£�û���ֵı��Ϊ�����ֹ����Ϊ1
*��ʼ�����resΪ1���������ֵ�������res��res++
*j�ӵ㣺 �д���1e5�����ݳ��֣���ʵ����res�ķ�Χ��1e5��
*/
#include <stdio.h>
#include <string.h>

#define N 110000

int a[N];

int main() {
    int n, res = 1;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; ++i) {
        int tmp; scanf("%d", &tmp);
        if (tmp <= 0) continue;
        if (tmp >= N) continue;
        a[tmp] = 1;
        if (tmp == res) {
            while (a[res]) res++;
        }
    }
    printf("%d\n", res);
    return 0;
}
