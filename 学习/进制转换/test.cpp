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
        printf("输入0结束，其他字符继续:");
        scanf("%c",&c);
        if (c == '0') break;
        printf("请输入一个十进制数：");
        scanf("%d", &x); getchar();
        while (x) {
            s[n++] = x % 2 + '0';
            x /= 2;
        }
        printf("该数对应的二进制为:");
        for (int i = n - 1; i >= 0; i--)
            putchar(s[i]);
        puts("");
    }
    return 0;
}
