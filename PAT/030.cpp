/*
*��Ŀ���ӣ�https://pintia.cn/problem-sets/994805342720868352/problems/994805507225665536
*���ⲽ�裺
*      1������ȷ�����Ƶ�������ΪS1
*      2����S1ǿתΪʮ����
*      3�������ֵ���Сֵ����ΪMIN(S1, MAX({val(S[i]) | i < len(S) and i >= 0}))
*      4�������ֵ����ֵ����ΪMAX(S1, MAX({val(S[i]) | i < len(S) and i >= 0}))
*      5�����ֽ���
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 320

typedef long long int ll;

ll INF = 1;

ll ma[N];
int n, m;
char s1[N], s2[N];

void init() {   //Ԥ����ӳ��
    INF = INF << 60;
    for (char c = '0'; c <= '9'; ++c) ma[c] = c - '0';
    for (char c = 'a'; c <= 'z'; ++c) ma[c] = (c - 'a') + 10;
}

/*
*�ú�������һ����������ʾ��Դ����תΪʮ���ƺ��ֵ
*���У�s��Ҫת�������ݣ�radix�ǿ�ʼ�Ľ��ƣ�target��Ŀ�����
*/
ll convert(char s[], ll radix, ll key) {
    ll res = 0;
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        res = res * radix + ma[s[i]];
        if (res < 0 || res > key) return -1;
    }
    return res;
}

int cmp(char s[], ll mid, ll key) {
    ll val = convert(s, mid, key);
    if (val < 0 || val > key) return 1;
    else if (val == key) return 0;
    else return -1;
}

/*
*�˺��������ĸ�����
*low�����½磬high�����Ͻ磬key����Ҫ���ҵ�ֵ
*/
ll binarySearch(char s[], ll low, ll high, ll key) {
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll status = cmp(s, mid, key);
        if (status == 0) return mid;
        else if (status < 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int tag, radix;
    init();
    while (scanf("%s %s %d %d", s1, s2, &tag, &radix) != EOF) {
        n = strlen(s1), m = strlen(s2);
        if (tag == 2) swap(s1, s2);
        ll val1 = convert(s1, (ll)radix, INF);
        ll low = -1;
        for (int i = 0; i < m; ++i) low = max(low, ma[s2[i]]);
        ll res = binarySearch(s2, low, max(low, val1), val1);
        if (res == -1) puts("Impossible");
        else printf("%lld\n", res);
    }
    return 0;
}
