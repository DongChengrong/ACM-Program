#include <stdio.h>
#include <string.h>

#define N 111000

char s[N];
int n = 0, x;

void init() {
    memset(s, 0, sizeof(s));
    n = 0;
}

int main() {
    while (1) {
        char c;
        init();
        printf("����0�����������ַ�����:");
        scanf("%c",&c);
        if (c == '0') break;
        printf("������һ��ʮ��������");
        scanf("%d", &x); getchar();
        while (x) {
            s[n++] = x % 2 + '0';
            x /= 2;
        }
        printf("������Ӧ�Ķ�����Ϊ:");
        for (int i = n - 1; i >= 0; i--)
            putchar(s[i]);
        puts("");
    }
    return 0;
}
