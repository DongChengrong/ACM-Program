/*
ʵ��û���뵽�ղž�ȻWA�ˣ�����ԭ����û�п��ǵ���������
ʹ�ö��ֲ��ҵ�һ����Ҫ�����ǲ��ҵ����������ź����
������ʹ�ö��ֲ���֮ǰһ��Ҫ��֤�������ź���ģ�����һ�ݴ���û���������Ի�WA
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 510
#define cin(x) scanf("%lld",&x)

typedef long long LL;

int l,n,m,k;
LL a[N], b[N], c[N], d[N * N];

void read(LL a[], int n) {
    for(int i = 0; i < n; i++) {
        cin(a[i]);
    }
}

bool check(LL x) {
    for(int i = 0; i < m; i++) {
        LL y = x - c[i];
        int p = lower_bound(d, d + k, y) - d;
        if(p < k && d[p] == y) return true;
    }
    return false;
}

int main() {
    int T = 1;
    while(scanf("%d%d%d",&l,&n,&m) == 3) {

        LL x,s;
        k = 0;

        printf("Case %d:\n",T++);

        read(a,l); read(b, n); read(c, m);

        for(int i = 0; i < l; i++)
            for(int j = 0; j < n; j++) {
                d[k++] = a[i] + b[j];
            }

        sort(d, d + k); //ǧ��ǵ�Ҫ����

        cin(s);
        while(s--) {
            cin(x);
            if(check(x)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
