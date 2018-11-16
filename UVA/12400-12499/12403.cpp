/*
*   UVA  12403
*  ��Ŀ���ӣ�https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=279&page=show_problem&problem=3834
*  ������������ģ���⣬���ӲҪ˵(ʵ����û��)��ʲô�ѵ�Ļ����Ǿ�ֻ�����ж�����ָ����
*  ����֪��c���Եı�׼�����ṩ��һ���ȽϺ���strcmp���ڱȽ������ַ����Ƿ���ȣ��������ǿ���
* ʹ������������б����ǽ��յ���������ָ���ʵ����������ȫû�б�Ҫ�������O(N)�ĺ�����
* �����ͱ���������ָ�����ע�⵽donation��report������ĸ��һ�£���������ֻ��Ҫ�Ƚ����
* �ַ���������ĸ�͹��ˣ�ʱ�临�ӶȽ�ΪO(1)
*/
#include <stdio.h>

typedef long long ll;

#define N 15

char s[N];

int main() {
    int T;
    ll money = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        if (s[0] == 'd') {
            ll x; scanf("%lld", &x); money += x;
        } else {
            printf("%lld\n", money);
        }
    }
    return 0;
}
