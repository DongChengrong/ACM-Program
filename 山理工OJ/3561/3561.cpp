#include<stdio.h>
#include<algorithm>
using namespace std;

int num[50],res[50];

void init()
{
    num[1]=num[2]=1;
    for(int i=3;i<=45;i++) num[i]=num[i-1]+num[i-2];
}

void solve(int n)
{
    if(n<=0) printf("-1\n");
    int cur=0,m;
    m=n;
    while(m)
    {
        res[cur++]=upper_bound(num+1,num+45,m)-num-1;
        m-=num[res[cur-1]];
    }
    printf("%d=",n);
    for(int i=cur-1;i>0;i--) printf("%d+",num[res[i]]);
    printf("%d\n",num[res[0]]);
}

int main()
{
    int t,n;
    init();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        solve(n);
    }
    return 0;
}
