//题目链接；http://118.190.20.162/view.page?gpid=T77
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

#define N 110

struct Node {
    int table;
    string lable, id;
    vector<string> anc_lable[N], anc_id[N];
};

int n, m;
Node a[N];

string format(string s) {   //将字符串统一用小写
    int len = s.length();
    for (int i = 0; i < len; ++i) s[i] = tolower(s[i]);
    return s;
}

void read() {   //读入并做预处理
    scanf("%d%d", &n, &m); getchar();
    for (int i = 1; i <= n; ++i) {
        string line;
        getline(cin, line);
        int index = 0;
        while (line[index] == '.') ++index;
        a[i].table = index / 2;
        a[i].lable = a[i].id = "";
        if (line.find('#') == line.npos) a[i].lable = format(line.substr(index));
        else  {
            a[i].lable = format(line.substr(index, line.find('#') - index - 1));
            a[i].id = line.substr(line.find('#'));
        }
        for (int j = 1; j < i; ++j) {
            int table = a[j].table;
            if (table >= index / 2) continue;
            if (a[j].id != "") a[i].anc_id[table].push_back(a[j].id);
            a[i].anc_lable[table].push_back(a[j].lable);
        }
    }
}

void solve() {
    for (int i = 1; i <= m; ++i) {
        string line;
        int ans[N], k = 0;
        memset(ans, 0, sizeof(ans));
        getline(cin, line);
        if (line.find(' ') == line.npos && line.find('#') == line.npos) {  //只有标签
            for (int j = 1; j <= n; ++j){
                if (a[j].lable == format(line)) ans[k++] = j;
            }
        } else if (line.find(' ') == line.npos && line.find('#') != line.npos) {  //只有id
            for (int j = 1; j <= n; ++j) if (a[j].id == line) ans[k++] = j;
        } else {
            for (int j = 1; j <= n; ++j) {
                string s;
                stack<string> sta;
                stringstream ss(line);
                int cnt = 0;
                while (ss >> s) {
                    sta.push(s); ++cnt;
                }
                s = sta.top(); sta.pop();

                if (s[0] == '#' && s != a[j].id) continue;
                else if (s[0] != '#' && format(s) != a[j].lable) continue;

                int sum = 1;
                for (int p = a[j].table - 1; p >= 0; --p) {
                    s = sta.top();
                    if (s[0] == '#') {
                        for (int q = 0; q < a[j].anc_id[p].size(); ++q) {
                            if (a[j].anc_id[p][q] == s) { ++sum; sta.pop(); break; }
                        }
                    } else {
                        s = format(s);
                        for (int q = 0; q < a[j].anc_lable[p].size(); ++q) {
                            if (a[j].anc_lable[p][q] == s) { ++sum; sta.pop(); break; }
                        }
                    }
                    if (sum == cnt) { ans[k++] = j; break; }
                }
            }
        }
        sort(ans, ans + k);
        printf("%d%c", k, k ? ' ' : '\n');
        for (int j = 0; j < k; ++j) {  //输出结果
            printf("%d%c", ans[j], j == k - 1 ? '\n' : ' ');
        }
    }
}

int main() {
    read();
    solve();
    return 0;
}
/*
11 5
html
..head
....title
..body
....h1
....p #subtitle
....div #main
......h2
......p #none
......div
........p #two
p
#subtitle
h3
div p
div div p
*/
