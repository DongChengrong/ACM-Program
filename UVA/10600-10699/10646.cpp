#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int get(string s) {
    if (isdigit(s[0])) return s[0] - '0';
    return 10;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        string s;
        vector<string> vec, tmp;
        int y = 0;
        for (int i = 0; i < 27; ++i) { cin >> s; vec.push_back(s); }
        for (int i = 27; i < 52; ++i) { cin >> s; tmp.push_back(s); }
        for (int i = 0; i < 3; ++i) {
            s = vec[vec.size() - 1];
            int x = get(s);
            y += x;
            //cout << s << '\n';
            vec.pop_back();
            int z = 10 - x;
            vec.resize(vec.size() - z);
        }
        for (int i = 0; i < tmp.size(); ++i) vec.push_back(tmp[i]);
        //printf("%d\n", y);
        printf("Case %d: ", kase);
        cout << vec[y - 1] << '\n';
    }
    return 0;
}
