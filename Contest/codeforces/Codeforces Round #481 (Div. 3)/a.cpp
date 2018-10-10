#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

#define N 1100
#define M 110

int a[M], vis[N];

int main() {
    int n;
    while (scanf("%d",&n) == 1) {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; ++i) scanf("%d",&a[i]);
        for (int i = n - 1; i >= 0; i--) {
            if (vis[a[i]]) a[i] = -1;
            else {
                vis[a[i]] = 1;
            }
        }

        vector<int> v;
        for (int i = 0; i < n; ++i) {
            if (a[i] != -1) v.push_back(a[i]);
        }

        printf("%d\n",v.size());
        for (int i = 0; i < v.size(); ++i) {
            printf("%d%c",v[i], i == v.size() - 1 ? '\n' : ' ');
        }
    }
    return 0;
}