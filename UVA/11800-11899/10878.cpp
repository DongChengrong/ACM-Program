//模拟水题，只要知道最原始的打孔计算机和
//二进制、asii码即可AC此题
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
