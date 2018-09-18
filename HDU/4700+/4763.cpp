#include <stdio.h>
#include <string.h>
#include <unordered_map>

using namespace std;

#define N 1100000

int f[N];
char s[N];

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        int len = strlen(s);
        f[0] = f[1] = 0;
        unordered_map<int, int> ma;
        for (int i = 1; i < len; ++i) {
            int j = f[i];
            while (j && s[i] != s[j]) j = f[j];
            f[i + 1] = (s[i] == s[j] ? j + 1 : 0);
        }
        int res = 0;
        printf("%d\n", res);
    }
    return 0;
}
