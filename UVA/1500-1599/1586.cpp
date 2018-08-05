#include <stdio.h>
#include <string.h>
#include <unordered_map>

using namespace std;

#define N 110

unordered_map<char, double> ma;

char s[N];

void init() {
    ma['C'] = 12.01; ma['H'] = 1.008;
    ma['O'] = 16; ma['N'] = 14.01;
}

int main() {
    int T;
    init();
    scanf("%d", &T);
    while (T--) {
        double ans = 0, tmp = 0;
        int i = 0, n, cnt = 0;
        scanf("%s", s);
        n = strlen(s);
        while (i < n) {
            if ( 'A' <= s[i] && s[i] <= 'Z') {
                ans += tmp * (cnt == 0 ? 1 : cnt );
                cnt = 0; tmp = ma[s[i]];
            } else cnt = cnt * 10 + s[i] - '0';
            ++i;
        }
        ans += tmp * (cnt == 0 ? 1 : cnt );
        printf("%.3f\n", ans);
    }
    return 0;
}
