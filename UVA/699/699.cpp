#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=100000+10;
int sum[maxn],left;

void build(int pos)
{
    int v;
    scanf("%d",&v);
    if(v==-1) return;
    if(left>pos) left=pos;
    sum[pos]+=v;
    build(pos-1);
    build(pos+1);
}

int init()
{
    int x;
    scanf("%d",&x);
    if(x==-1) return 0;
    memset(sum,0,sizeof(sum));
    int pos=maxn/2; left=pos;
    sum[pos]=x;
    return 1;
}

int main()
{
    int Test=0;
    while(init())
    {
        build(maxn/2-1);
        build(maxn/2+1);
        printf("Case %d:\n%d",++Test,sum[left]);
        for(int i=left+1;sum[i]!=0;i++) printf(" %d",sum[i]);
        printf("\n\n");
    }
    return 0;
}
