//ģ��ˮ�⣬ֻҪ֪����ԭʼ�Ĵ�׼������
//�����ơ�asii�뼴��AC����
#include <stdio.h>
#include <string.h>

#define N 110

char s[N];
int a[N] = { 0, 128, 64, 32, 16, 8, 0, 4, 2, 1 };

int decode() {
    int sum = 0, i;
    int n = strlen(s);
    for (i = 0; i < n; ++i) {
        if (s[i] == 'o') sum += a[i];
    }
    return sum;
}

int main() {
    gets(s);
    while (gets(s) && strcmp(s, "___________")) {
        printf("%c", decode());
    }
    return 0;
}
