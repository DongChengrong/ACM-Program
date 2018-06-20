/*
记忆化搜索，非常巧妙的是这里封装了一个篮子类
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define H 50
#define INF 0x3f3f3f3f

int n;
int pile[4][H], dp[H][H][H][H];

struct Basket {
    int sz;
    int color[H];

    Basket() {
        sz = 0;
        memset(color, 0, sizeof(color));
    }

    int isFull() {
        return sz == 5;
    }

    int take(int top) {
        color[top] = 0;
        sz--;
    }

    int put(int top) {
        color[top] = 1;
        sz++;
    }
};

int dfs(Basket bs, vector<int> hs) {
    int &res = dp[hs[0]][hs[1]][hs[2]][hs[3]];
    if (res != -1) return res;
    res = 0;
    if (bs.isFull()) return res;
    for (int i = 0; i < hs.size(); ++i) {
        int &h = hs[i];
        int sum = 0;
        if (h <= 0) continue;
        int top = pile[i][h - 1];
        h--;
        if (bs.color[top]) {
            bs.take(top);
            sum = dfs(bs, hs) + 1;
            bs.put(top);
        }
        else if (!bs.isFull()) {
            bs.put(top);
            sum = dfs(bs, hs);
            bs.take(top);
        }
        res = max(res, sum);
        h++;
    }
    return res;
}

int main() {
    while (scanf("%d",&n) == 1 && n) {
        vector<int> hs(4);
        hs.assign(4, n);
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 4; ++j)
                scanf("%d",&pile[j][n - 1 - i]);
        }
        Basket bs;
        int res = dfs(bs, hs);
        printf("%d\n",res);
    }
    return 0;
}
