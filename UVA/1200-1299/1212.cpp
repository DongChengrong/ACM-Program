#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<int,int> ma;

#define N 310000

int cnt;
int cost[N];

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        int n; cnt = 1;
        int ans = 0;
        scanf("%d", &n); getchar();
        for (int i = 0; i < n; ++i) {
            string s;
            getline(cin, s); stringstream ss(s);
            int c, x; ss >> c;
            while (ss >> x) {
                ma[x] = cnt;
            }
            ans += c;
            cost[cnt] = c;
            cnt++;
        }
        scanf("%d", &n); getchar();
        for (int i = 0; i < n; ++i) {
            string s;
            getline(cin, s); stringstream ss(s);
            int c, x, tmp = 0; ss >> c;
            while (ss >> x) {
                int p = ma[x];
                if (p) {
                    tmp += cost[p];
                    cost[p] = 0;
                }
            }
            ans = ans + c - min(c, tmp);
        }
        printf("Case %d:\n%d\n", kase, ans);
        if (kase != T) puts("");
    }
    return 0;
}
