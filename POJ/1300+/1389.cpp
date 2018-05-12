#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

#define N 1100

int pa[30], d[30], vis[30];
char s[N];

int findset(int x) {
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

void init() {
    for (int i = 0; i < 26; ++i) pa[i] = i;
    memset(d, 0, sizeof(d));
    memset(vis, 0, sizeof(vis));
}

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        init();
        int cnt = 26;
        while (n--) {
            scanf("%s",s);
            int ss = s[strlen(s) - 1] - 'a';
            int t = s[0] - 'a';
            d[ss]++; d[t]--;
            vis[ss] = vis[t] = 1;
            int x = findset(ss);
            int y = findset(t);
            if (x != y) {
                cnt--;
                pa[x] = y;
            }
        }

        vector<int> vec;
        for (int i = 0; i < 26; ++i) {
            if (!vis[i]) cnt--;
            if (d[i] != 0) vec.push_back(d[i]);
        }

        sort(vec.begin(), vec.end());

        if (cnt == 1 && (vec.empty() || (vec.size() == 2 && vec[0] == -1 && vec[1] == 1)))
            puts("Ordering is possible.");
        else puts("The door cannot be opened.");
    }
    return 0;
}
