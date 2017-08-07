#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

string line;
map<long long, int> base;
int sum;

void dfs(int depth, int s ,int e) {
    if(line[s] == '[') {
        int p = 0;
        for(int i = s + 1; i != e; ++i) {
            if(line[i] == '[') ++p;
            if(line[i] == ']') --p;
            if(p == 0 && line[i] == ',') {
                dfs(depth + 1, s + 1, i - 1);
                dfs(depth + 1, i + 1, e - 1);
            }
        }
    } else {
        long long w = 0;
        for(int i = s; i <= e; ++i) w = w * 10 + line[i] - '0';
        ++sum, ++base[w << depth];
    }
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        cin >> line;
        base.clear();
        sum = 0;
        dfs(0, 0, line.size() - 1);

        int maxn = 0;
        for(map<long long,int >::iterator it = base.begin(); it != base.end(); ++it)
            maxn = max(maxn, it->second);

        cout << sum - maxn << endl;
    }
}
