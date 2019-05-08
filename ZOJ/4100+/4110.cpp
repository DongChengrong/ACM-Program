
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long ll;

#define N 2200000

ll n;
ll len[2 * N];

ll manachar(string str) {
    memset(len, 0, sizeof(int) * (n * 2 + 100));
    ll mx = 0, p = 0, cnt = 0;
    string s = "$";
    for (int i = 0; i < n; ++i) { s += '#'; s += str[i]; } s += '#';
    n = s.size();
    for (int i = 1; i < n; ++i) {
        if (mx > i) len[i] = min(mx - i, len[2 * p - i]);
        else len[i] = 1;
        while (s[i - len[i]] == s[i + len[i] ]) len[i]++;
        if (len[i] + i > mx) mx = len[i] + i, p = i;
        cnt += len[i] / 2;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        string s1, s2;
        cin >> s1 >> s2;
        n = s1.size();
        if (s1 == s2) cout << manachar(s1) << '\n';
        else {
            string tmp1 = "", tmp2 = "";
            int s = -1, e = -1;
            for (int i = 0; i < n; ++i) {
                if (s1[i] != s2[i]) {
                    if (s == -1) s = i; else e = i;
                }
            }
            if (s != -1 && e == -1) cout << "0\n";
            else {
                for (int i = s; i <= e; ++i) tmp1 += s1[i], tmp2 += s2[i];
                reverse(tmp1.begin(), tmp1.end());
                if (tmp1 != tmp2) cout << "0\n";
                else {
                    ll res = 1;
                    for (int i = 1; e + i < n && s - i >= 0; ++i) {
                        if (s1[s - i] != s1[e + i]) break;
                        ++res;
                    }
                    cout << res << '\n';
                }
            }
        }
    }
    return 0;
}
