#include<stdio.h>
#include<algorithm>
using namespace std;

#define N 110

int a[N];

int main()
{
    int n,x,m,cnt;
    while(scanf("%d%d",&n,&m) == 2)
    {
        cnt = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[cnt]);
            if(a[cnt] < 0) cnt++;
        }

        sort(a,a+cnt);

        int sum = 0;
        for(int i = 0; i < cnt && i < m; i++)
            sum += a[i];

        printf("%d\n",-sum);
    }
    return 0;
}
