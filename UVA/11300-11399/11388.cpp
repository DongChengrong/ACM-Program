/*
��������У���ʹ������Ŀ�������ԣ�a,b�����ڣ������l % g == 0
����������������Ľ�ʱ��Ҫ����a��С����a = g
��ʱa * b / g = l �� g * b / g = l
�༴b = l
*/

#include <stdio.h>

int main() {
    int T, l, g;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&g,&l);
        if (l % g != 0) {
            printf("-1\n");
        } else {
            printf("%d %d\n",g,l);
        }
    }
    return 0;
}
