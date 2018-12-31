#include <stdio.h>
#include <string.h>

char s[110];
char code[30] = "22233344455566677778889999";

int main() {
    while (scanf("%s", s) != EOF) {
        int len = strlen(s);
        for (int i = 0; i < len; ++i) {
            if ('A' <= s[i] && s[i] <= 'Z') putchar(code[s[i] - 'A' ]);
            else putchar(s[i]);
        }
        puts("");
    }
    return 0;
}
