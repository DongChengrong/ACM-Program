#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <map>
#include <math.h>
#include <sstream>

using namespace std;

typedef long long ll;

map<string, ll> ma;

void init() {
    ma["bool"] = ma["char"] = 1;
    ma["int"] = ma["float"] = 4;
    ma["long long"] = ma["double"] = 8;
    ma["__int128"] = ma["long double"] = 16;
}

int main() {
    init();
    int T; scanf("%d",&T); getchar();
    for (int kase = 1; kase <= T; ++kase) {
        ll res = 0;
        string line;
        int n; scanf("%d", &n); getchar();
        for (int i = 0; i < n; ++i) {
            string tmp, type = "";
            int flag = 0;
            getline(cin, line);
            stringstream ss(line);
            while (ss >> tmp) {
                if (!flag) {
                    type += tmp;
                    if (ma[type]) flag = 2;
                    else flag = 1;
                } else if (flag == 1) {
                    type += " "; type += tmp;
                    flag = 2;
                } else if (flag == 2) {
                    ll num = 0, mark = 0;
                    int sz = tmp.size();
                    for (int i = 0; i < sz; ++i) {
                        if (tmp[i] == ']') break;
                        if (tmp[i] == '[') { mark = 1; continue; }
                        if (mark == 1) num = num * 10 + (tmp[i] - '0');
                    }
                    if (!num) num = 1;
                    res = res + (num * ma[type]);
                }
            }
        }
        printf("Case #%d: %I64d\n", kase, (ll)ceil((double)res / 1024.0));
    }
    return 0;
}
