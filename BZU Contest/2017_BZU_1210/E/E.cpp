#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 20000 + 100;
int heads[maxn], knights[maxn];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) == 2 && n)
    {
        for(int  i = 1; i <= n; i++)   //the size of head
            scanf("%d",&heads[i]);

        for(int i = 1; i <= m; i++)   //the cost of knight
            scanf("%d",&knights[i]);

        //从小到大排序
        sort(heads + 1, heads + n + 1);
        sort(knights + 1, knights + m + 1);

        //slove
        int sum = 0;
        int i,j;
        i = j = 1; //i代表恶龙，j代表勇士
        while(i <= n && j <= m)  //恶龙的头
        {
            if(j > m) break;  //已经没有勇士了
            if(heads[i] > knights[j]) j++;
            else
            {
                sum += knights[j++];
                i++;
            }
        }
        if(i <= n) printf("Loowater is doomed!\n");
        else printf("%d\n",sum);
    }
	return 0;
}
