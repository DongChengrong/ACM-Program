#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int t,n,z,p,b;
    int sb,sp,mb,mp;
    double key,k;
    scanf("%d",&t);
    while(t--)
    {
        sb=0;
        sp=0;
        scanf("%d",&n);
        while(n--)
        {
            key=0;
            scanf("%d",&z);
            while(z--)
            {
                scanf("%d%d",&p,&b);
                k=(double)b/(double)p;
                if(k>key)
                {
                   key=k;
                   mb=b;
                   mp=p;
                }
            }
            sb+=mb;
            sp+=mp;
        }
        k=(double)sb/(double)sp;
        printf("%.3lf",k);
    }
    return 0;
}
