//题目链接：https://pintia.cn/problem-sets/994805260223102976/problems/994805299301433344
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long ll;

const char s[15] = "0123456789A";

int main() {
    ll a, b, c;
    while (scanf("%lld%lld%lld", &a, &b, &c) != EOF) {
        char res[100];
        int cnt = 0;
        if (c == 10) { printf("%lld\n", a + b); continue; }
        ll sum = a + b;
        if (sum == 0) { printf("0\n"); continue; }
        while (sum) {
            res[cnt++] = s[sum % c]; sum /= c;
        }
        res[cnt] = '\0';
        reverse(res, res + cnt);
        puts(res);
    }
    return 0;
}
