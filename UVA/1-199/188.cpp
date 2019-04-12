#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <math.h>

using namespace std;

#define N 110

typedef long long ll;

int n;
string a[N];
ll b[N], c;

ll id(string s) {
    reverse(s.begin(), s.end());
    int sz = s.size();
    ll res = 0;
    for (int i = 0; i < sz; ++i)  res = res + pow(32, i) * (s[i] - 'a' + 1);
    return res;
}

int test() {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((c / b[i]) % n == (c / b[j]) % n) {
                c = min(((c / b[i]) + 1)*b[i], ((c / b[j]) + 1)*b[j]); return 0;
            }
        }
    }
    return 1;
}

int main() {
    string line;
    while (getline(cin, line)) {
        n = 0;
        stringstream ss(line);
        while (ss >> a[n++]); n--;
        for (int i = 0; i < n; ++i) b[i] = id(a[i]);
        sort(b, b + n);
        c = b[0];
        while (!test());
        cout << line << '\n';
        cout << c << "\n\n";
    }
    return 0;
}
