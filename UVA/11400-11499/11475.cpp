/*
*分析：这个题还是简单的KMP的应用
* 我们先把原字符串复制到另一个字符数组里，然后再把这个新的数组反转，用作模板串
* 然后我们在打出他的失配函数
* 最后我们对这两个字符串进行匹配，得到最后p数组的偏移量
* 先输出S字符串，再输出加上偏移量的P字符串
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
