#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 10 + 10;

int main()
{
    int n;
    double k;
    while(~scanf("%d%lf",&n,&k))
    {
        int ans = 0, tmp = 0;

        for(int i = 1; i <= n; i++)
        {
            tmp += k;
            int d = tmp % 10;
            if(d == 6 || d == 7 || d == 8 || d == 9)
            {
                ans += (int)(tmp * 0.9 + 0.5);
                tmp = 0;
            }
        }
        ans += (int)(tmp * 0.9 + 0.5);
        printf("%d\n",ans);
    }
	return 0;
}
