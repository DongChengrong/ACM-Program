/*
*题目链接：https://pintia.cn/problem-sets/994805342720868352/problems/994805519074574336
*分析：简单模拟
*坑点：注意n为0的情况
*/
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

char s[1100];
char str[15][15] = { "zero", "one", "two", "three", "four", "five", "six",
 "seven", "eight", "nine" , "ten"};

int sum() {
    int res = 0, m = strlen(s);
    for (int i = 0; i < m; ++i) res += s[i] - '0';
    return res;
}

int main() {
    while (scanf("%s", s) != EOF) {
        vector<int> res;
        int n = sum();
        if (!n) { puts("zero"); continue; }
        while (n) {
            res.push_back(n % 10);
            n /= 10;
        }
        for (int i = res.size() - 1; i >= 0; --i) {
            printf("%s%c", str[res[i]], i == 0 ? '\n' : ' ');
        }
    }
    return 0;
}
