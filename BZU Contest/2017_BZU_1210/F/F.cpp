#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1000 + 10;

struct Job
{
    int b,j;
}a[maxn];

int cmp(Job a, Job b)
{
    return a.j > b.j;
}

int main()
{
    int n,T = 1;
    while(~scanf("%d",&n) && n)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d%d",&a[i].b,&a[i].j);

        int Max = 0, end = 0;
        sort(a + 1, a + n + 1,cmp);

        for(int i = 1; i <= n; i++)
        {
            end = end + a[i].b;  //每个人收到任务的时间
            Max = max(Max, end + a[i].j);
        }
        printf("Case %d: %d\n",T++,Max);
    }
	return 0;
}
