#include <stdio.h>

#define N 55

int n, ans;
int a[N];

bool dfs(int cur, int now,int deep) {
    if (cur > deep || (now << (deep - cur) < n) || now <= 0)
        return false;
    if (now << (deep - cur) == n)
        return true;

    a[cur] = now;

    for (int i = 0; i <= cur; ++i) {
        if (dfs(cur + 1, now + a[i], deep))
            return true;
        if (dfs(cur + 1, now - a[i], deep))
            return true;
    }

    return false;
}

int main() {
    while (scanf("%d", &n) && n) {
        for (ans = 0; !dfs(0, 1, ans); ++ans);
        printf("%d\n", ans);
    }
    return 0;
}
