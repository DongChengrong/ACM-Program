#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 110000
#define _for(i, a, b) for (int i = (a); i < (b); ++i)

int pa[N];
int x, y;

void init() {
    _for (i, 0, N) pa[i] = i;
}

int findset(int x) {
    return x == pa[x] ? pa[x] : pa[x] = findset(pa[x]);
}

int main() {
    init();
    int cnt = 0;
    while (scanf("%d",&x) == 1) {
        if(x == -1) {
            printf("%d\n",cnt);
            cnt = 0; init();
            continue;
        }
        scanf("%d", &y);
        x = findset(x); y = findset(y);
        if (x == y) cnt++;
        else pa[x] = y;
    }
    return 0;
}
