#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define N 15

char s1[N], s2[N], s3[N];

unordered_map<char, int> ma;
vector< vector<int> > base;

void dfs(vector<int> a, int cur, int n) {
    if (cur == n) {
        base.push_back(a); return;
    }
    for (int j = 0; j <= 9; ++j) {
        int flag = 1;
        for (int k = 0; k < a.size(); ++k) {
            if (a[k] == j) flag = 0;
        }
        if (flag) {
            a.push_back(j);
            dfs(a, cur + 1, n);
            a.pop_back();
        }
    }
}

int todigit(char s[], vector<int> b) {
    int res = 0;
    int len = strlen(s);
    if (len > 1 &&  b[ma[s[0]] - 1] == 0) return -1;
    for (int i = 0; i < len; ++i) res = res * 10 + b[ma[s[i]] - 1];
    return res;
}

int main() {

    //freopen("out.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        int cnt = 0;
        int k = 1;
        scanf("%s %s %s", s1, s2, s3);

        base.clear(); ma.clear();
        for (int i = 0; i < strlen(s1); ++i) if (!ma[s1[i]]) ma[s1[i]] = k++;
        for (int i = 0; i < strlen(s2); ++i) if (!ma[s2[i]]) ma[s2[i]] = k++;
        for (int i = 0; i < strlen(s3); ++i) if (!ma[s3[i]]) ma[s3[i]] = k++;

        for (int i = 0; i <= 9; ++i) {
            vector<int> v1(1, i);
            dfs(v1, 1, ma.size());
        }
        int n = base.size();

        for (int i = 0; i < n; ++i) {

            int a = todigit(s1, base[i]);
            int b = todigit(s2, base[i]);
            int c = todigit(s3, base[i]);

            if (a == -1 || b == -1 || c == -1) continue;
            if (a + b == c) ++cnt;
            if (a - b == c) ++cnt;
            if (a * b == c) ++cnt;
            if (b != 0 && a / b == c && a % b == 0) ++cnt;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
