#include<cstdio>
#include<map>
#include<queue>
using namespace std;

const int maxn=1000+10;
char order[10];

int main()
{
    int num,ans,test=1;
    while(scanf("%d",&num)==1 && num)
    {
        int k;
        ans=0;
        map<int,int> m;
        queue<int> a;
        queue<int> b[maxn];
        printf("Scenario #%d\n",test++);
        for(int i=0;i<num;i++)
        {
            scanf("%d",&k);
            while(k--) { int x; scanf("%d",&x); m[x]=ans; }
            ans++;
        }
        while(scanf("%s",order)==1 && order[0]!='S')
        {
            getchar();
            if(order[0]=='E')
            {
                int x;
                scanf("%d",&x);
                int pos=m[x];
                if(b[pos].empty()) a.push(pos);
                b[pos].push(x);
            }
            else if(order[0]=='D')
            {
                int pos=a.front();
                printf("%d\n",b[pos].front()); b[pos].pop();
                if(b[pos].empty()) a.pop();
            }
        }
        printf("\n");
    }
    return 0;
}
