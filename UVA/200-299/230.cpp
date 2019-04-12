#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define N 210000

struct Book{
    string title, author;
    bool operator < (const Book &u) const {
        return author < u.author || (author == u.author && title < u.title);
    }
};

int vis[N];
unordered_map<string, int> ma;
vector<Book> shelves, tmp;

void pre() {
    string line;
    memset(vis, 0, sizeof(vis));
    while (getline(cin, line) && line != "END") {
        Book book = (Book){ line.substr(0, line.substr(1).find('\"') + 2),
            line.substr(line.substr(1).find('\"') + 6) };
        shelves.push_back(book);
    }
    sort(shelves.begin(), shelves.end());
    for (int i = 0; i < shelves.size(); ++i) ma[shelves[i].title] = i;
}

void solve() {
    string line;
    while (getline(cin, line) && line != "END") {
        if (line[0] == 'B') {
            string title = line.substr(line.find(' ') + 1);
            int pos = ma[title]; vis[pos] = 1;
        } else if (line[0] == 'R') {
            string title = line.substr(line.find(' ') + 1);
            int pos = ma[title]; tmp.push_back(shelves[pos]);
        } else if (line[0] == 'S') {
            sort(tmp.begin(), tmp.end());
            for (int i = 0; i < tmp.size(); ++i) {
                int pos = ma[tmp[i].title];
                int j = pos - 1;
                while (j >= 0) if (!vis[j]) break; else --j;
                if (j == -1) cout << "Put " << tmp[i].title <<" first\n";
                else cout << "Put " << tmp[i].title << " after " << shelves[j].title << '\n';
                vis[pos] = 0;
            }
            tmp.clear();
            cout << "END\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    pre();
    solve();
    return 0;
}
