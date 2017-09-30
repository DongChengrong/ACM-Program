#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int x,sum = 0, maxn = -105;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&x);
            sum += x;
            maxn = max(maxn,sum);
            //如果sum小于0，要想值最大只有不选择
            if(sum < 0) sum = 0;
        }
        printf("%d\n",maxn);
    }
    return 0;
}
