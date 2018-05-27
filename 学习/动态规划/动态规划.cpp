#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

#define N 110
#define M 110000

int m, n;
int a[N], b[M];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("oil.in", "r", stdin);
    freopen("oil.out", "w", stdout);
    #endif // ONLINE_JUDGE
    while (scanf("%d%d",&m, &n) == 2) {
        for (int i = 0; i < n; ++i) scanf("%d",&a[i]);
        memset(b, 0, sizeof(b));
        b[0] = 1;
        vector<int> tmp; tmp.push_back(0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < tmp.size(); ++j) {
                int u = a[i];
                int v = tmp[j];
                if (!b[u + v]) tmp.push_back(u + v);
                b[u + v] = 1;
            }
        }
        if (b[m]) puts("yes");
        else puts("no");
    }
    return 0;
}
