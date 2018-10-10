#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 110000

int a[N], b[N], c[N];

int main() {
    int n, x;
    while (scanf("%d %d", &n, &x) != EOF) {
        int flag = 0;
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            b[a[i]]++;
            if (b[a[i]] >= 2) flag = 1;
        }
        vector<int> vec;
        if (flag) { puts("0"); continue; }
        for (int i = 0; i < n; ++i) {
            int tmp = (a[i] & x);
            if (tmp == a[i]) continue;
            if (b[tmp] == 1) {
                flag = 1; break;
            } else vec.push_back(tmp);
        }
        if (flag) { puts("1"); continue; }
        for (int i = 0; i < vec.size(); ++i) {
            int tmp = vec[i];
            c[tmp]++;
            //printf("%d\n", tmp);
            if (c[tmp] >= 2) {
                flag = 1; break;
            }
        }
        if (flag) puts("2");
        else puts("-1");
    }
    return 0;
}
