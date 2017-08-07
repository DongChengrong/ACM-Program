#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=25;
bool vis[maxn];
int N,k,m;
int a,b;

int seekA()
{
    int i=k,pos=a;
    while(1)
    {
        if(!vis[pos]) i--;
        if(!i) break;
        pos=(pos+1)%N;
    }
    return pos;
}

int seekB()
{
    int i=m,pos=b;
    while(1)
    {
        if(!vis[pos]) i--;
        if(!i) break;
        pos=(pos+N-1)%N;
    }
    return pos;
}

int main()
{
    int t;
    while(scanf("%d %d %d",&N,&k,&m)==3 && N)
    {
        a=0;
        b=N-1;
        t=N;
        memset(vis,false,sizeof(vis));
        while(t>0)
        {
            a=seekA();
            b=seekB();
            printf("%3d",a+1); t--;
            if(a!=b) { printf("%3d",b+1); t--; }
            if(t) printf(",");
            vis[a]=vis[b]=true;
            a=(a+1)%N; b=(b-1+N)%N;
        }
        printf("\n");
    }
    return 0;
}
