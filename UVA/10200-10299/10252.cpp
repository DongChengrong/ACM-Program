#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

#define N 11000

int vis1[30], vis2[30];

int main() {
    string s, t;
    while (getline(cin, s)) {
        getline(cin, t);
        memset(vis1, 0, sizeof(vis1));
        memset(vis2, 0, sizeof(vis2));
        int n = s.size();
        int m = t.size();
        for (int i = 0; i < n; ++i) vis1[s[i] - 'a' ]++;
        for (int i = 0; i < m; ++i) vis2[t[i] - 'a' ]++;
        for (int i = 0; i < 26; ++i) while (vis1[i] && vis2[i]) {
            printf("%c", 'a' + i);
            vis1[i]--, vis2[i]--;
        }
        puts("");
    }
    return 0;
}
