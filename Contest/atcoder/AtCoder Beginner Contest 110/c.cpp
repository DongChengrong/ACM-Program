#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
    string s, t;
    while (cin >> s >> t) {
        int len = s.size(), i;
        for (i = 0; i < len; ++i) {
            if (s.find(s[i]) != t.find(t[i])) break;
        }
        if(i < len) puts("No");
        else puts("Yes");
    }
    return 0;
}

/*
第二种解法
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 210000

int a[30], b[30];
char s1[N], s2[N];

int main() {
    while (scanf("%s", s1) != EOF) {
        scanf("%s", s2);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int i, n = strlen(s1);
        for (i = 0; i < n; ++i) {
            a[s1[i] - 'a']++;
            b[s2[i] - 'a']++;
        }
        sort(a, a + 26); sort(b, b + 26);
        for (i = 0; i < 26; ++i) {
            if (a[i] != b[i]) break;
        }
        if (i < 26) puts("No");
        else puts("Yes");
    }
    return 0;
}
*/
