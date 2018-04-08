#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn =  10000 + 10;
double a[maxn];
int n,k;

bool F(double x)
{
    int num = 0;
    for(int i = 0; i < n; i++)
        num += (int)(a[i] / x);
    return num >= k;
}

int main()
{
    while(scanf("%d%d",&n,&k) == 2)
    {
        for(int i = 0; i < n; i++)
            scanf("%lf",&a[i]);
        sort(a, a + n);
        double l = 0,r = INF;
        for(int i = 0; i < 100; i++)
        {
            double mid = (l + r) / 2;
            if(F(mid)) l = mid;
            else r = mid;
        }
        printf("%.2lf\n",floor(r * 100) / 100);
    }
    return 0;
}
