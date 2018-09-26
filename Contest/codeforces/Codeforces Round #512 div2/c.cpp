#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 2100
#define INF 0x3f3f3f3f

char s[N];
int pre[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        scanf("%s", s);
        pre[0] = 0;
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + (s[i - 1] - '0');
        }
        pre[n + 1] = 11000;
        int flag = 0;
        for (int i = 1; i < n; ++i) {
            if (flag) break;
            int val = pre[i], j = i, key = 2 * val;
            if (key == pre[n]) flag = 1;  //ÓÅ»¯
            if (key >= pre[n]) continue;
            while (1) {
                int p = lower_bound(pre + j + 1, pre + n + 3, key) - pre;
                if (pre[p] != key) break;
                else if (pre[p] == key && p == n) {flag = 1; break;}
                else if (pre[p] == key && pre[p] == pre[n]) { flag = 1; break; }
                else j = p, key = key + val;
            }
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
