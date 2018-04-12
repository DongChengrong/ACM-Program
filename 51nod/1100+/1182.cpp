/*
̰���㷨�Ĺؼ��ط�����̰�Ĳ��Ե�ȷ���� ��ˣ�
����ÿһ��̰���㷨���������Ƕ�Ӧ����ȷ������̰�Ĳ���
��������⣬����̰�Ĳ����ǰѴ������������ִ��������ĸ
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
