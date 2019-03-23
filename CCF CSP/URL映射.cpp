//ÌâÄ¿Á´½Ó£ºhttp://118.190.20.162/view.page?gpid=T71
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

#define N 110

struct Node {
    string url;
    vector<string> urls;
};

int n, m;
Node a[N];
map<string, string> ma;

vector<string> url_split(string s) {
    vector<string> res;
    int len = s.length();
    int i = 0, j = 1;
    while (j < len) {
        if (s[j] != '/') ++j;
        else {
            res.push_back(s.substr(i + 1, j - i - 1));
            i = j; j += 1;
        }
    }
    if (i == len - 1) res.push_back("");
    else res.push_back(s.substr(i + 1));
    return res;
}

int digit(string s) {
    int len = s.size();
    for (int i = 0; i < len; ++i) if (!isdigit(s[i])) return 0;
    return 1;
}

string tostr(string s) {
    int pos = 0;
    while (s[pos] == '0') ++pos;
    return s.substr(pos);
}

int legal(string s) {
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        if (isalpha(s[i])) continue;
        if (isdigit(s[i])) continue;
        if (s[i] == '-' || s[i] == '.' || s[i] == '_') continue;
        return 0;
    }
    return 1;
}

int main() {
    scanf("%d%d", &n, &m); getchar();
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        a[i].url = line.substr(0, line.find(' '));
        a[i].urls = url_split(a[i].url);
        ma[a[i].url] = line.substr(line.find(' ') + 1);
    }
    while (m--) {
        int i;
        string address;
        getline(cin, address);
        //if (!legal(address)) { puts("404"); continue; }
        vector<string> addr = url_split(address);
        for (i = 0; i < n; ++i) {
            vector<string> res;
            if (addr.size() < a[i].urls.size()) continue;
            int len = addr.size(), j;
            for (j = 0; j < len; ++j) {
                if (a[i].urls.size() < j + 1) break;
                string s1 = addr[j], s2 = a[i].urls[j];
                if (s2 == "<int>") {
                    if (!digit(s1)) break;
                    res.push_back(tostr(s1));
                } else if (s2 == "<str>") {
                    if (!legal(s1)) break;
                    res.push_back(s1);
                } else if (s2 == "<path>") {
                    for (int k = j + 1; k < len; ++k) s1 += "/" + addr[k];
                    res.push_back(s1);
                    j = len; break;
                } else {
                    if (s1 != s2) break;
                }
            }
            if (j >= len) {
                cout << ma[a[i].url];
                if (res.size()) {
                    printf(" ");
                    for (int k = 0; k < res.size(); ++k) {
                        cout << res[k] << (k == res.size() - 1 ? '\n' : ' ');
                    }
                } else puts("");
                break;
            }
        }
        if (i == n) puts("404");
    }
    return 0;
}
