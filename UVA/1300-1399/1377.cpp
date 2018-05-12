#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define N 1100000
#define INF 0x3f3f3f3f

int n,cnt,m,mm;
int has[N],ans[N],res[N],vis[N],a[N];

void print() {
    sort(res, res + m);
    printf("%d\n",m);
    for (int i = 0; i < m; ++i) {
        printf("%d%c",res[i], i == m - 1 ? '\n' : ' ');
    }
}

void add(int x) {
    for (int i = 0; i < mm; ++i) {
        int dif = abs(x - ans[i]);
        if (has[dif] == -1) continue;
        if (has[dif] == 0) cnt++;
        has[dif]++;
    }
    vis[x] = 1;
    ans[mm++] = x;
}

void del(int x) {
    for (int i = 0; i < mm; ++i) {
        int dif = abs(x - ans[i]);
        if (has[dif] == -1) continue;
        if (has[dif] == 1) cnt--;
        has[dif]--;
    }
    vis[x] = 0;
    mm--;
}

void dfs() {
    //printf("%d\n",mm);
    if (cnt == n) {
        if(m == -1 || (m > mm)) {
            memcpy(res,ans,sizeof(ans));
            m = mm;
        }
        return;
    }
    if(cnt > n) return;
    if(mm > 7) return;

    for (int i = 0; i < n; ++i) {
        if(!vis[a[i]]) {
            add(a[i]);
            dfs();
            del(a[i]);
        }
    }
}

int main() {
    int x, T = 1;
    while (scanf("%d",&n) == 1 && n) {
        printf("Case %d:\n",T++);

        int MIN = -1, MAX = INF;

        memset(has, -1, sizeof(has));
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < n; ++i) {
            scanf("%d",&a[i]);
            has[a[i]] = 0;
        }

        sort(a, a + n);

        if (n == 1) {
            printf("1\n0 %d\n",a[0]);
            continue;
        }

        mm = 0,m = -1;

        add(0); add(a[0]); add(a[n - 1]);

        dfs();
        print();
    }
    return 0;
}
