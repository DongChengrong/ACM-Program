#include <string>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, int> ma;

bool check(char c) {
    if (isdigit(c)) return true;
    if (isalpha(c)) return true;
    return false;
}

int main() {
    string line;
    while (getline(cin, line)) {
        line += ' ';
        ma.clear();
        int max_num = -1;
        string cur_str = "";
        string res_str = "";
        int n = line.length();
        for (int i = 0; i < n; ++i) {
            if (check(line[i])) {
                cur_str += tolower(line[i]);
            } else {
                if (cur_str == "") continue;
                ma[cur_str]++;
                if (ma[cur_str] > max_num) {
                    max_num = ma[cur_str];
                    res_str = cur_str;
                } else if (ma[cur_str] == max_num) {
                    res_str = res_str < cur_str ? res_str : cur_str;
                }
                cur_str = "";
            }
        }
        cout << res_str << " " << max_num << '\n';
    }
    return 0;
}
