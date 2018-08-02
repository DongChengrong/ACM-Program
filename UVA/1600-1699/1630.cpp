#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

#define N 105
#define INF 0x3f3f3f3f

string s;
string fold[N][N];

int get_cycle(int l, int r) {
    for (int i = 1; i <= (r - l + 1) / 2; ++i) {
        bool flag = true;
        if ((r - l + 1) % i) continue;
        for (int j = l; j <= r - i; ++j) {
            if (s[j] == s[j + i]) continue;
            flag = false;
        }
        if (flag) return i;
    }
    return 0;
}

string &dp(int l, int r) {
    string &ans = fold[l][r];
    if (!ans.empty()) return ans;
    if (l == r) return ans = s[l];

    int anslen = INF;
    for (int i = l; i < r; ++i) {
        string tmp = dp(l, i) + dp(i + 1, r);
        if (tmp.size() < anslen) {
            anslen = tmp.size();
            ans = tmp;
        }
    }

    int cycle = get_cycle(l, r);
    if (cycle) {
        stringstream ss;
        ss << (r - l + 1) / cycle << "(" << dp(l, l + cycle - 1) << ")";
        if (ss.tellp() < anslen) {
            anslen = ss.tellp();
            ss >> ans;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> s) {
        int n = s.size() - 1;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                fold[i][j].clear();
        cout << dp(0, n) << '\n';
    }
    return 0;
}
