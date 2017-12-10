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
        int i;
        for(i = 1; i <= n; i++)
            if((int)(i * k * 0.9 + 0.5) < floor((int)(i * k * 0.9)))
                break;

        printf("%d\n",i);
    }
	return 0;
}
