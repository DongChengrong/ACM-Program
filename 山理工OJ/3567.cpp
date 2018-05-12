#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 110000

int n, id, pos;
char s[N];
char tmp[N];

unordered_map<string, int> ma;

struct Node {
    int l, r;
}ID[N];

void init() {
    id = n = pos = 0;
    ma.clear();
    memset(s, 0, sizeof(s));
}

void _define() {
    while (scanf("%s",tmp) == 1) {
        int x = 0;
        bool flag = false;
        int len = strlen(tmp);
        string name = "";
        for (int i = 0; i < len; ++i) {
            if (tmp[i] == '[') { flag = true; continue; }
            if (tmp[i] == ']') break;
            if (!flag) name += tmp[i];
            else x = x * 10 + tmp[i] - '0';
        }
        ma[name] = id; ID[id].l = n;
        s[n] = '\0'; n += x;
        ID[id++].r = n;
        char c = getchar();
        if (c == '\n') break;
    }
}

void _gets() {
    string name;
    cin >> name;
    int id = ma[name]; getchar();
    gets(tmp);
    int len = strlen(tmp);

    int i, j;
    for (i = ID[id].l, j = 0; i < ID[id].r && j < len; ++i, ++j) {
        s[i] = tmp[j];
    }

    if (i < ID[id].r) s[i] = '\0';
}

void _cout() {
    string name;
    cin >> name;
    int id = ma[name];
    s[n] = '\0';
    puts(s + ID[id].l);
}

int main() {
    int T;
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    scanf("%d",&T);
    while (T--) {
        init();
        while (1) {
            string cmd;
            cin >> cmd;
            if (cmd == "return") { cin >> cmd; break; }
            if (cmd == "char") _define();
            if (cmd == "gets") _gets();
            if (cmd == "cout") _cout();
        }
    }
    return 0;
}
