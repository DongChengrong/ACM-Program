#include<cstdio>
#include<cstring>
#include<queue>
#include<math.h>
using namespace std;

typedef struct Node
{
    int step,value;
}P;

const int maxn=10000+10;
bool vis[maxn];
int prime[maxn];
queue<P> q;
int start,end;

int isPrime(int n)
{
    if(n<=1) return 0;
    int m=floor(sqrt(n)+0.5);
    for(int i=2;i<=m;i++) if(n%i==0) return 0;
    return 1;
}

void bfs()
{
    queue<P> q;
    P p;
    p.value=start,p.step=0;
    vis[p.value]=true;
    q.push(p);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        if(p.value==end) { printf("%d\n",p.step); return; }
        else
        {
            for(int i=0;i<=9;i++)
            {
                P temp;
                temp.value=(p.value/10)*10+i;
                temp.step=p.step+1;
                if(temp.value>1000 && temp.value<10000 && prime[temp.value] && !vis[temp.value]) { q.push(temp); vis[temp.value]=true;}
            }
            for(int i=0;i<=9;i++)
            {
                P temp;
                int mod=p.value%10;
                temp.value=(p.value/100)*100+mod+i*10;
                temp.step=p.step+1;
                if(temp.value>1000 && temp.value<10000 && prime[temp.value] && !vis[temp.value]) { q.push(temp); vis[temp.value]=true;}
            }
            for(int i=0;i<=9;i++)
            {
                P temp;
                int mod=p.value%100;
                temp.value=(p.value/1000)*1000+mod+i*100;
                temp.step=p.step+1;
                if(temp.value>1000 && temp.value<10000 && prime[temp.value] && !vis[temp.value]) { q.push(temp); vis[temp.value]=true;}
            }
            for(int i=1;i<=9;i++)
            {
                P temp;
                int mod=p.value%1000;
                temp.value=(p.value/10000)+mod+i*1000;
                temp.step=p.step+1;
                if(temp.value>1000 && temp.value<10000 && prime[temp.value] && !vis[temp.value]) { q.push(temp); vis[temp.value]=true;}
            }
        }
    }
    printf("Impossible\n");
}

int main()
{
    int T;
    for(int i=1000;i<=9999;i++) prime[i]=isPrime(i);
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,false,sizeof(vis));
        scanf("%d %d",&start,&end);
        if(start==end) printf("0\n");
        else if(!prime[end]) printf("Impossible\n");
        else bfs();
    }
    return 0;
}
