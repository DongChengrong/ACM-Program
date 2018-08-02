#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define N 22000
#define M 55

struct Node {
    int t, p;
    string keyword;
    vector<string> title;
    bool operator < (Node u) {
        if (keyword != u.keyword) return keyword < u.keyword;
        if (t != u.t) return t < u.t;
        return p < u.p;
    }
};

int n, m, t;
Node res[N];
unordered_map<string, int> ma;

void print(Node u) {
    for (int i = 0; i < u.title.size(); ++i) {
        cout << u.title[i] << (i == u.title.size() - 1 ? '\n' : ' ');
    }
}

string low(string s) {
    for (int i = 0; i < s.size(); ++i) s[i] = tolower(s[i]);
    return s;
}

string upp(string s) {
    for (int i = 0; i < s.size(); ++i) s[i] = toupper(s[i]);
    return s;
}

vector<string> change(vector<string> base, int i) {
    base[i] = upp(base[i]);
    return base;
}

void add(vector<string> base, string key, int t, int p) {
    res[n++] = (Node) {t, p, upp(key), base};
}

int main() {

//    #ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    #endif // ONLINE_JUDGE

    string s;
    t = n = m = 0;
    ma.clear();
    //ios_base::sync_with_stdio(false);
    while (cin >> s && s != "::") ma[s] = 1;
    while (getline(cin, s)) {
        string tmp;
        stringstream ss(s);
        vector<string> base;
        while (ss >> s) base.push_back(low(s));
        for (int i = 0; i < base.size(); ++i) {
            if (ma[base[i]]) continue;
            add(change(base, i), base[i], t, i);
        }
        ++t;
    }
    sort(res, res + n);
    for (int i = 0; i < n; ++i) print(res[i]);
    return 0;
}
