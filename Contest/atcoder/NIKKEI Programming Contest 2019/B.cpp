#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 110
#define _for(i, a, b) for (int i = (a); i < (b); ++i)

typedef long long ll;

char s1[N], s2[N], s3[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int res = 0;
        scanf("%s%s%s", s1, s2, s3);
        for (int i = 0; i < n; ++i) {
            if (s1[i] == s2[i] && s2[i] == s3[i]) continue;
            else if (s1[i] != s2[i] && s2[i] != s3[i] && s1[i] != s3[i]) res += 2;
            else ++res;
        }
        printf("%d\n", res);
    }
    return 0;
}
