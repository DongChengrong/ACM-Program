/*
��Ŀ����: http://acm.hdu.edu.cn/showproblem.php?pid=1686
������kmp�������⣬ֱ��ʹ��KMP�㷨�Ϳ�����
�����Ŀ�����ڰ���ѧϰ���ݽṹ���㷨��ͬѧ����KMP
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 1001000
#define M 11000

int n, m;   //n:s�ĳ��� m:t�ĳ���
char s[M], t[N];   //s:ģʽ�� t:�ı���
int ne[M];  //next����

void read() {
    scanf("%s", s);
    scanf("%s", t);
    n = strlen(s);
    m = strlen(t);
}

//ʧ�亯�����ܶ�̲��ϳ�Ϊ����next����
void getFail() {
    int i = 1;
    ne[0] = ne[1] = 0;
    for (i = 1; i < n; ++i) {
        int j = ne[i];   //Ҫ��ƥ����Ҫ����Сλ����
        while (j && s[i] != s[j]) j = ne[j];
        ne[i + 1] = (s[j] == s[i] ? j + 1 : 0);
    }
}

//KMP�����㷨������getFail�õ�next����
int kmp() {
    getFail();
    int i, j = 0;
    int num = 0;
    for (i = 0; i < m; ++i) {
        while (j && t[i] != s[j]) j = ne[j];
        if (s[j] == t[i]) ++j;
        if (j >= n) {  //�ҵ�һ��ƥ����ַ���
            ++num; j = ne[n];
        }
    }
    return num;
}

void solve() {
    printf("%d\n", kmp());
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        read(); solve();
    }
    return 0;
}
