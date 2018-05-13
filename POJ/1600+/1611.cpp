#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define N 33000

int pa[N];
vector<int> vec[N];

void init(int n) {
    for (int i = 0; i <= n; ++i) {
        pa[i] = i;
        vec[i].clear();
        vec[i].push_back(i);
    }
}

int findset(int x) {
    return pa[x] == x ? pa[x] : pa[x] = findset(pa[x]);
}

int main() {
    int n, m;
    while (scanf("%d%d",&n, &m) == 2 && n) {
        init(n);
        while (m--) {
            int num, x, y, tmp;
            scanf("%d",&num);
            if (!num) continue;
            scanf("%d",&tmp); x = findset(tmp); num--;
            for (int i = 0; i < num; i++) {
                scanf("%d",&tmp);
                y = findset(tmp);
                if (x != y) {
                    if (vec[x].size() > vec[y].size()) swap(x, y);
                    pa[x] = y;
                    for (int j = 0; j < vec[x].size(); ++j) {
                        vec[y].push_back(vec[x][j]);
                    }
                    x = y;
                }
            }
        }
        int x = findset(0);
        printf("%d\n", vec[x].size());
    }
    return 0;
}
