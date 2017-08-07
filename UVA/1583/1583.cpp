#include<cstdio>
#include<cstring>
using namespace std;

int len;

void comlen(int n)
{
    while(n)
    {
        len++;
        n/=10;
    }
}

int comvalue(int m)
{
    int value=m;
    while(m)
    {
        value+=m%10;
        m/=10;
    }
    return value;
}

int main()
{
    int T,n,m;
    scanf("%d",&T);
    while(T--)
    {
        int ok=0;
        len=0;
        scanf("%d",&n);
        comlen(n);
        for(int i=n-9*len;i<n;i++)
        {
            if(i<=0) continue;
            m=comvalue(i);
            if(m==n) { ok=1; m=i; break; }
        }
        if(ok) printf("%d\n",m);
        else printf("0\n");
    }
    return 0;
}
