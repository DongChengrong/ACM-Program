#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define N 110000

int cnt;
map<string, int> ma;

struct Node {
    int a = 0, b = 0, c = 0;
    int n, score;
    string school;

    void convert() {
        score = 0;
        if (a) score += a * 1.5;
        if (b) score += b;
        if (c) score += c / 1.5;
    }

    bool operator < (const Node &u) const {
        if (score != u.score) return score > u.score;
        if (n != u.n) return n < u.n;
        return school < u.school;
    }
};

Node a[N];

void _tolower(string &s) {
    int n = s.length();
    for (int i = 0; i < n; ++i) s[i] = tolower(s[i]);
}

int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int score;
        string name, school;
        cin >> name >> score >> school;
        _tolower(school);
        int tmp, id;
        if (ma[school]) {
            id = ma[school];
            a[id].n++; a[id].score = a[id].score + tmp;
        } else {
            id = ma[school] = ++cnt;
            a[id].n = 1; a[id].score = tmp;
            a[id].school = school;
            a[id].a = a[id].b = a[id].c = 0;
        }
        if (name[0] == 'T') a[id].a += score;
        if (name[0] == 'A') a[id].b += score;
        if (name[0] == 'B') a[id].c += score;
    }
    for (int i = 1; i <= cnt; ++i) a[i].convert();

    cout << cnt << '\n';
    int rank = 1;
    sort(a + 1, a + cnt + 1);
    for (int i = 1; i <= cnt; ++i) {
        if (i != 0) if (a[i].score < a[i - 1].score) rank = i;
        cout << rank << " " << a[i].school << " " << (int)a[i].score << " " \
        << a[i].n << '\n';
    }
    return 0;
}
