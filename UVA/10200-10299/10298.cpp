#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 100;

int f[maxn];
string s;

void getFail(string s) {
    int n = s.size();
    f[0] = f[1] = 0;
    for (int i = 1; i < n; ++i) {
        int j = f[i];
        while (j && s[i] != s[j]) j = f[j];
        f[i + 1] = (s[i] == s[j] ? j + 1 : 0);
    }
}

int main() {
    while (getline(cin, s)) {
        int n = s.size();
        if (s.size() == 0) {
            cout << 0 << '\n';
            continue;
        }
        if (s[0] == '.') break;

        getFail(s);
        int k = n - f[n];
        cout << ((k != 0 && n % k == 0) ? n / k : 1) << '\n';
    }
    return 0;
}
