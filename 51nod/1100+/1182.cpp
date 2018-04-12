/*
贪心算法的关键地方在于贪心策略的确定， 因此，
对于每一个贪心算法的问题我们都应该先确定他的贪心策略
对于这个题，他的贪心策略是把大的数分配给出现次数多的字母
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 11000

char s[N];
int d[30];

int main() {
    memset(d, 0, sizeof(d));
    scanf("%s",s);
    for (int i = 0; i < strlen(s); ++i) {
        int p;
        if ( 'A' <= s[i] && s[i] <= 'Z') s[i] -= 'A' - 'a';
        p = s[i] - 'a';
        ++d[p];
    }

    sort(d, d + 26);

    int ans = 0;

    for (int i = 0; i < 26; ++i)
        ans += d[i] * (i + 1);

    printf("%d\n",ans);

    return 0;
}
