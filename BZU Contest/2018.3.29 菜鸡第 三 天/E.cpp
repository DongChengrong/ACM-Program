/*
��������������Ĳ�����T�Ŀ��м���������
�Ƚϼ򵥣����Ը���ǰһ��״̬����
����������ط�Ҫע�⣬һ���Ǳ߽磬��һ���������ж��ܷ�ת��
*/

#include<stdio.h>

#define N 200100

typedef long long LL;

LL a[N];

int main()
{
    LL n,t,c;
    while(scanf("%lld%lld%lld",&n,&t,&c) == 3)
    {
        for(int i = 1; i <= n; i++)
            scanf("%lld",&a[i]);

        int i,j,cnt = 0;
        i = j = 1;
        while(j <= n){
            if(a[j] <= t) j++;
            else {
                i = j = (j + 1);
            }
            if(j - i ==  c){
                cnt++; i++;
            }

        }
        printf("%d\n",cnt);
    }
    return 0;
}
