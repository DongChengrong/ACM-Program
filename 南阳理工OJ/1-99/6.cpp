#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn=600+10;
double R[maxn];

double l(double r)
{
    return sqrt(r*r-1)*2;
}

int cmp(double x,double y)
{
    return x>y;
}

int main()
{
    int Test;
    scanf("%d",&Test);
    while(Test--)
    {
        int n;
        double len=20;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%lf",&R[i]);
        sort(R,R+n,cmp);
        int ans=0,i=0;
        while(len>0)
        {
            ans++;
            len-=l(R[i++]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
