#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct Node {
    char c;
    int num;
    bool operator < (const Node &u) const {
        return num < u.num;
    }
};

int cc;

bool check(string s) {
    Node a[10];   //a, b, c, d出现的次数
    for (int i = 0; i < 4; ++i) a[i].num = 0, a[i].c = 'A' + i;  //初始化
    //依次判断每个条件是否满足
    if ((s[1] - 'A' + 2) % 4 != (s[4] - 'A')) return false;    //检验第二个题目要求
    //检验第三题题目要求
    if (s[2] == 'A') if (s[2] == s[5] || s[5] != s[1] || s[5] != s[3]) return false;
    if (s[2] == 'B') if (s[5] == s[2] || s[2] != s[1] || s[2] != s[3]) return false;
    if (s[2] == 'C') if (s[1] == s[2] || s[2] != s[5] || s[2] != s[3]) return false;
    if (s[2] == 'D') if (s[3] == s[2] || s[2] != s[5] || s[2] != s[1]) return false;
    //检验第四个题目要求
    if (s[3] == 'A') if (s[0] != s[4]) return false;
    if (s[3] == 'B') if (s[1] != s[6]) return false;
    if (s[3] == 'C') if (s[0] != s[8]) return false;
    if (s[3] == 'D') if (s[5] != s[9]) return false;
    //检验第五题的条件
    if (s[4] == 'A' && s[4] != s[7]) return false;
    if (s[4] == 'B' && s[4] != s[3]) return false;
    if (s[4] == 'C' && s[4] != s[8]) return false;
    if (s[4] == 'D' && s[4] != s[6]) return false;
    //检验第六题的条件
    if (s[5] == 'A') if (s[1] != s[3] || s[1] != s[7]) return false;
    if (s[5] == 'B') if (s[0] != s[5] || s[0] != s[7]) return false;
    if (s[5] == 'C') if (s[2] != s[9] || s[2] != s[7]) return false;
    if (s[5] == 'D') if (s[4] != s[8] || s[4] != s[7]) return false;
    //统计每个选项出现次数
    for (int i = 0; i < 10; ++i) a[s[i] - 'A'].num++;
    sort(a, a + 4);
    //检查第七题条件
    if (s[6] == 'A' && 'C' != a[0].c) return false;
    if (s[6] == 'B' && 'B' != a[0].c) return false;
    if (s[6] == 'C' && 'A' != a[0].c) return false;
    if (s[6] == 'D' && 'D' != a[0].c) return false;
    //检查第十题的条件
    if (s[9] == 'A' && (a[3].num - a[0].num) != 3) return false;
    if (s[9] == 'B' && (a[3].num - a[0].num) != 2) return false;
    if (s[9] == 'C' && (a[3].num - a[0].num) != 4) return false;
    if (s[9] == 'D' && (a[3].num - a[0].num) != 1) return false;
    //检查第八题条件
    if (s[7] == 'A' && (max(s[0], s[6]) - min(s[0], s[6])) == 1) return false;
    if (s[7] == 'B' && (max(s[0], s[4]) - min(s[0], s[4])) == 1) return false;
    if (s[7] == 'B' && (max(s[0], s[1]) - min(s[0], s[1])) == 1) return false;
    if (s[7] == 'B' && (max(s[0], s[9]) - min(s[0], s[9])) == 1) return false;
    //检查第九题的条件
    if (s[0] == s[5]) {
        if (s[8] == 'A' && s[5] == s[4]) return false;
        if (s[8] == 'B' && s[9] == s[4]) return false;
        if (s[8] == 'C' && s[1] == s[4]) return false;
        if (s[8] == 'D' && s[8] == s[4]) return false;
    } else {
        if (s[8] == 'A' && s[5] != s[4]) return false;
        if (s[8] == 'B' && s[9] != s[4]) return false;
        if (s[8] == 'C' && s[1] != s[4]) return false;
        if (s[8] == 'D' && s[8] != s[4]) return false;
    }
    return true;
}

void dfs(string s, int cnt) {
    if (cnt == 10) {
        if (check(s)) { cout << s << endl; cc++;}
        return;
    }
    for (int i = 0; i < 4; ++i) {
        string tmp = s;
        dfs(tmp += (i + 'A'), cnt + 1);
    }
}

int main() {
    cc = 0;
    //freopen("out.txt", "w", stdout);
    string s = "";
    for (int i = 0; i < 4; ++i) {
        string tmp = s;
        dfs(tmp += ('A' + i), 1);
    }
    //cout << cc << endl;
    return 0;
}
