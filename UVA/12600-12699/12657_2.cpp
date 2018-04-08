#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100000+10;
int left[maxn],right[maxn],inv;

void link(int L,int R)
{
    left[R]=L;
    right[L]=R;
}

long long number(int n)
{
    int x=0;
    long long total=0;
    for(int i=1;i<=n;i++)
    {
        x=right[x];
        if(i%2) total+=x;
    }
    if(inv && n%2==0) total=(long long)n*(n+1)/2-total;
    return total;
}

int main()
{
    int n,m,T=1;
    while(scanf("%d %d",&n,&m)==2)
    {
        //init
        for(int i=1;i<=n;i++)
        {
            left[i]=i-1;
            right[i]=(i+1)%(n+1);
        }
        right[0]=1; left[0]=n;
        inv=0;

        while(m--)
        {
            int order,X,Y;
            scanf("%d",&order);
            if(order==4)
            {
                inv=!inv;
                continue;
            }
            scanf("%d %d",&X,&Y);
            if(order!=3 && inv) order=3-order;

            int LX,RX,LY,RY;
            LX=left[X]; RX=right[X]; LY=left[Y]; RY=right[Y];
            if(order==1)
            {
                link(X,Y); link(LX,RX); link(LY,X);
            }
            else if(order==2)
            {
                link(Y,X); link(LX,RX); link(X,RY);
            }
            else if(order==3)
            {
                link(LX,Y); link(Y,RX); link(LY,X); link(X,RY);
            }
        }
        printf("Case %d: %lld\n",T++,number(n));
    }
    return 0;
}

/*³ö´íÊý¾Ý
4 1
3 2 3
*/
