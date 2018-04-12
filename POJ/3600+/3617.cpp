#include <stdio.h>
#include <string.h>
using namespace std;

#define N 2200

char s[N], tmp[5], t[N];

int chose(int &st, int &e) {
    int cur = st, i = st, j = e;
    while (i < j) {
        if (s[i] < s[j]) {
            ++st; break;
        } else if (s[i] > s[j]) {
            cur = e; --e; break;
        }
        ++i; --j;
    }
    if (i >= j) ++st;
    return cur;
}

int main() {
    int n;
    while (scanf("%d",&n) == 1 ) {

        for (int i = 0; i < n; ++i) {
            scanf("%s",tmp);
            s[i] = tmp[0];
        }

        int id = 0,i = 0, j = n - 1;
        while (id < n) {
            int p = chose(i,j);
            t[id++] = s[p];
        }

        for (int i = 0; i < n; ++i) {
            putchar(t[i]);
            if ((i + 1) % 80 == 0) putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}
