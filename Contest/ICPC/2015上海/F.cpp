#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 30
#define M 1100
#define INF 0x3f3f3f3f

char s[M];

int main() {
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k) {
        vector<int> base[N];
        printf("Case #%d: ", k);
        int MIN = INF;
        scanf("%s",s);
        int n = strlen(s);
        for (int i = 0; i < n; ++i) {
            base[s[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j < base[i].size(); ++j) MIN = min(MIN, base[i][j] - base[i][j - 1]);
        }
        if (MIN == INF) puts("-1");
        else printf("%d\n", MIN);
    }
    return 0;
}
