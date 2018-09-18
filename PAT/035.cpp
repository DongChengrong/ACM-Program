/*
*题目链接：https://pintia.cn/problem-sets/994805260223102976/problems/994805324509200384
*题目分类：简单模拟题
**/
#include <stdio.h>
#include <string.h>

#define N 1100

int num[N];
char s[20][20] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
char str[N];

int main() {
    while (scanf("%s", str) != EOF) {
        int sum = 0, cnt = 0;
        int n = strlen(str);
        for (int i = 0; i < n; ++i) {
            sum += (str[i] - '0');
        }
        while (sum) {
            num[cnt++] = sum % 10;
            sum /= 10;
        }
        for (int i = cnt - 1; i >= 0; --i) printf("%s%c", s[num[i]], i == 0 ? '\n' : ' ' );
    }
    return 0;
}
