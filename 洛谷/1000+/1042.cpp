#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define N 11000

char s[N];

string tostring(int x) {
    stringstream ss;
    ss << x;
    string tmp; ss >> tmp;
    return tmp;
}

int main() {
    vector<string> vec;
    int flag = 1;
    int cnt1 = 0, cnt2 = 0;
    int c1 = 0, c2 = 0;
    while (scanf("%s", s) != EOF) {
        int n = strlen(s), i;
        for (i = 0; i < n; ++i) {
            if (s[i] == 'E') break;
            flag = 0;
            if (s[i] == 'W') { cnt1++; ++c1; }
            if (s[i] == 'L') { cnt2++; ++c2; }
            if ((cnt1 >= 11 || cnt2 >= 11) && abs(cnt1 - cnt2) >= 2) {
                printf("%d:%d\n", cnt1, cnt2);
                cnt1 = cnt2 = 0;
            }
            if ((c1 >= 21 || c2 >= 21) && abs(c1 - c2) >= 2) {
                string tmp = tostring(c1) + ":" + tostring(c2) + "\n";
                c1 = c2 = 0;
                vec.push_back(tmp);
            }
        }
        if (s[i] == 'E') break;
    }
    printf("%d:%d\n", cnt1, cnt2);
    vec.push_back(tostring(c1) + ":" + tostring(c2) + "\n");
    puts("");
    for (int i = 0; i < vec.size(); ++i) cout << vec[i];
    return 0;
}
