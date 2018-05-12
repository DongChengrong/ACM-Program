#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 31000

char tmp[10];
int pa[N], cnt[N], s[N];

void init() {
    for (int i = 0; i < N; ++i) {
        pa[i] = i; cnt[i] = 0; s[i] = 1;
    }
}

int findset(int x) {
    if (x != pa[x]) {
        int f = pa[x];
        pa[x] = findset(pa[x]);
        cnt[x] += cnt[f];
    }
    return pa[x];
}

void unite(int x, int y) {
    //printf("1\n");
    x = findset(x);
    y = findset(y);
    if (x != y) {
        pa[x] = y;
        cnt[x] = s[y];
        s[y] += s[x];
    }
}

int main() {
    int q;
    init();
    scanf("%d",&q);
    while (q--) {
        int x, y;
        scanf("%s", tmp);
        if (tmp[0] == 'C') {
            scanf("%d",&x);
            findset(x);
            printf("%d\n",cnt[x]);
        } else if (tmp[0] == 'M') {
            scanf("%d%d",&x,&y);
            unite(x, y);
        }
    }
    return 0;
}
