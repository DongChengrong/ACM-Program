#include <stdio.h>
#include <string.h>
#include <stack>
#include <algorithm>

using namespace std;

#define N 220000

int n;
char s[N], col[N], res[N];

int check(int mid) {
    stack<int> red, blue;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            if (red.size() < mid) { col[i] = '1'; red.push(1); continue; }
            if (blue.size() < mid) { col[i] = '0'; blue.push(1); continue; }
            return 0;
        } else if (s[i] == ')') {
            if (red.size()) { col[i] = '1'; red.pop(); continue; }
            if (blue.size()) { col[i] = '0'; blue.pop(); continue; }
            return 0;
        }
    }
    if (red.size() || blue.size()) return 0;
    return 1;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        scanf("%s", s);
        int l = 1, r = N;
        while (l < r) {
            for (int i = 0; i < n; ++i) col[i] = '0';
            int mid = (l + r) / 2;
            //printf("%d\n", mid);
            if (check(mid)) { r = mid; for (int i = 0; i < n; ++i) res[i] = col[i]; }
            else l = mid + 1;
        }
        res[n] = '\0';
        puts(res);
    }
    return 0;
}