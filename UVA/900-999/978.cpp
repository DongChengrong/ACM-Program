#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int main() {
    int T, flag = 0;
    scanf("%d", &T);
    while (T--) {
        if (flag) puts("");
        else flag = 1;

        int g, sa, sb;
        priority_queue<int> a, b;
        scanf("%d %d %d", &g, &sa, &sb);
        for (int i = 0; i < sa; ++i) {
            int x; scanf("%d", &x);
            a.push(x);
        }
        for (int i = 0; i < sb; ++i) {
            int x; scanf("%d", &x);
            b.push(x);
        }
        while (!a.empty() && !b.empty()) {

        }
    }
    return 0;
}
