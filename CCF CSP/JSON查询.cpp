//ÌâÄ¿Á´½Ó£ºhttp://118.190.20.162/view.page?gpid=T61
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

string getstr(string s) {
    string res = "";
    s = s.substr(1, s.size() - 2);
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        if (s[i] != '\\') res += s[i];
        else res += s[i + 1], i += 1;
    }
    return res;
}

int main() {
    string line;
    getline(cin, line);
    return 0;
}
