//ÌâÄ¿Á´½Ó:https://www.nowcoder.com/pat/2/problem/370
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define N 110

int a[N];
char s[N];

int main() {
    while (scanf("%s",s) == 1) {
        int MAX = 0;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < strlen(s); ++i) {
            a[s[i] - '0']++;
            MAX = max(MAX, a[s[i] - '0']);
        }
        for (int i = MAX; i >= 1; --i) {
            for (int j = 0; j <= 9; ++j) {
                if (a[j] >= i) printf("*");
                else printf(" ");
            }
            puts("");
        }
        puts("0123456789");
    }
    return 0;
}
