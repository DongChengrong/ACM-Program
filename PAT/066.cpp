//problem link :https://www.nowcoder.com/pat/0/problem/3985
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, int> ma;

int f[55];

void init() {
    f[0] = 1; f[1] = 1;
    ma[1] = 1;
    for (int i = 2; ; ++i) {
        f[i] = f[i - 1] + f[i - 2];
        if (f[i] > 26) break;
        ma[f[i] ] = 1;
    }
}

int main() {
    init();
    string s;
    ios_base::sync_with_stdio(false);
    while (cin >> s) {
        set<string> set1;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 1; i + j <= n; ++j){
                string sub_str = s.substr(i, j);
                set<char> set2; int len = sub_str.size();
                for (int k = 0; k < len; ++k) set2.insert(sub_str[k]);
                if (ma[set2.size()]) set1.insert(sub_str);
            }
        }
        for (string str : set1) cout << str << '\n';
    }
    return 0;
}
