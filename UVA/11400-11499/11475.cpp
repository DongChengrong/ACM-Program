/*
*����������⻹�Ǽ򵥵�KMP��Ӧ��
* �����Ȱ�ԭ�ַ������Ƶ���һ���ַ������Ȼ���ٰ�����µ����鷴ת������ģ�崮
* Ȼ�������ڴ������ʧ�亯��
* ������Ƕ��������ַ�������ƥ�䣬�õ����p�����ƫ����
* �����S�ַ��������������ƫ������P�ַ���
**/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 101000

int f[N], n;
char s[N], p[N];

void getFail(char s[]) {
    f[0] = f[1] = 0;
    for (int i = 1; i < n; ++i) {
        int j = f[i];
        while (j && s[i] != s[j]) j = f[j];
        f[i + 1] = (s[i] == s[j] ? j + 1 : 0);
    }
}

int main() {
    while (scanf("%s", s) != EOF) {
        n = strlen(s);
        strcpy(p, s);
        reverse(p, p + n);
        getFail(p);
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (j && s[i] != p[j]) j = f[j];
            if (s[i] == p[j]) ++j;
        }
        printf("%s%s\n", s, p + j);
    }
    return 0;
}
