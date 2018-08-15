//迭代深搜 + 二分
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define N 100000
#define M 15

int n;
string base[N];
string s;

int low(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    else  return a < b;
}

void dfs(int cur, int cnt, int p, string buf) {
    if (cur == cnt) {
        base[n++] = buf;
        return;
    }

    for (int i = p + 1; i < 26; ++i) {
        string tmp = buf; tmp += 'a' + i;
        dfs(cur + 1, cnt, i, tmp);
    }
}

void init() {
    n = 0;
    for (int i = 1; i <= 5; ++i) {
        dfs(0, i, -1, "");
    }
}

int binary_search(int l, int r, string s) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (s == base[mid]) return mid;
        else if (low(s, base[mid])) {
            r = mid - 1;
        } else l = mid + 1;
    }
    return -1;
}

int main() {

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    init();
    ios_base::sync_with_stdio(false);
    while (cin >> s) {
        cout << binary_search(0, n - 1, s) + 1 << '\n';
    }
    return 0;
}
