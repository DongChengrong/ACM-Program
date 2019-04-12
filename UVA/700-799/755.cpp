#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <string>
#include <set>
#include <iostream>

using namespace std;

#define N 110000

struct Node{
    int n;
    string s;
    bool operator < (const Node &u) const {
        return s < u.s;
    }
};

int n, cnt;
int vis[N];
unordered_map<string, int> ma1;
unordered_map<char, char> ma2;
unordered_map<int, string> ma3;

int id(string s) {
    if (ma1[s]) return ma1[s];
    else {
        ma1[s] = (++cnt);
        ma3[cnt] = s;
        return cnt;
    }
}

string detail(string s) {
    int sz = s.size();
    string tmp = "";
    for (int i = 0; i < sz; ++i) {
        if (isdigit(s[i])) tmp += s[i];
        if (isalpha(s[i])) {
            tmp += ma2[s[i]];
        }
    }
    string res = tmp.substr(0, 3) + "-" + tmp.substr(3);
    return res;
}

int main() {
    int T; scanf("%d", &T);
    ma2['A'] = '2';ma2['B'] = '2';ma2['C'] = '2';
    ma2['D'] = '3';ma2['E'] = '3';ma2['F'] = '3';
    ma2['G'] = '4';ma2['H'] = '4';ma2['I'] = '4';
    ma2['J'] = '5';ma2['K'] = '5';ma2['L'] = '5';
    ma2['M'] =  '6';ma2['N'] =  '6';ma2['O'] = '6';
    ma2['P'] = '7';ma2['R'] = '7';ma2['S'] = '7';
    ma2['T'] = '8';ma2['U'] = '8';ma2['V'] = '8';
    ma2['W'] =  '9';ma2['X'] =  '9';ma2['Y'] = '9';
    while (T--) {
        cnt = 0;
        ma1.clear(); ma3.clear();
        memset(vis, 0, sizeof(vis));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            s = detail(s);
            int x = id(s);
            vis[x]++;
        }
        set<Node> s;
        for (int i = 1; i <= cnt; ++i) {
            if (vis[i] >= 2) s.insert((Node){vis[i],ma3[i] });
        }
        if (s.empty()) puts("No duplicates.");
        else {
            for (Node u : s) cout << u.s << " " << u.n << '\n';
        }
        if (T) puts("");
    }
    return 0;
}
