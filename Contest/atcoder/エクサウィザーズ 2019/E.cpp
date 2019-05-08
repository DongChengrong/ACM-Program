#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include <deque>

using namespace std;

#define N 11000

char s1[N], s2[N];

int main() {
    int T; scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        printf("Case #%d: ", kase);
        scanf("%s%s", s1, s2);
        deque<int> q1, q2;
        int sz = strlen(s1), sz2 = strlen(s2);
        for (int i = 0; i < sz; ++i) q1.push_back(s1[i] - '0');
        for (int i = 0; i < sz2; ++i) q2.push_back(s2[i] - '0');
        while (!q1.empty() || !q2.empty()) {
            int t1 = q1.front(), t2 = q1.back();
            int t3 = q2.front(), t4 = q2.back();
            int t = max(t1, max(t2, max(t3, t4)));
            printf("%d", t);
            if (t == t1) { q1.pop_front(); continue; }
            if (t == t2) { q1.pop_back(); continue; }
            if (t == t3) { q2.pop_front(); continue; }
            if (t == t4) { q2.pop_back(); continue; }
        }
    }
    return 0;
}
