/*
题目链接: http://acm.hdu.edu.cn/showproblem.php?pid=1686
分析：kmp的入门题，直接使用KMP算法就可以了
这个题目可用于帮助学习数据结构或算法的同学掌握KMP
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 1001000
#define M 11000

int n, m;   //n:s的长度 m:t的长度
char s[M], t[N];   //s:模式串 t:文本串
int ne[M];  //next数组

void read() {
    scanf("%s", s);
    scanf("%s", t);
    n = strlen(s);
    m = strlen(t);
}

//失配函数，很多教材上称为构建next数组
void getFail() {
    int i = 1;
    ne[0] = ne[1] = 0;
    for (i = 1; i < n; ++i) {
        int j = ne[i];   //要想匹配需要的最小位移量
        while (j && s[i] != s[j]) j = ne[j];
        ne[i + 1] = (s[j] == s[i] ? j + 1 : 0);
    }
}

//KMP的主算法，调用getFail得到next数组
int kmp() {
    getFail();
    int i, j = 0;
    int num = 0;
    for (i = 0; i < m; ++i) {
        while (j && t[i] != s[j]) j = ne[j];
        if (s[j] == t[i]) ++j;
        if (j >= n) {  //找到一个匹配的字符串
            ++num; j = ne[n];
        }
    }
    return num;
}

void solve() {
    printf("%d\n", kmp());
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        read(); solve();
    }
    return 0;
}
