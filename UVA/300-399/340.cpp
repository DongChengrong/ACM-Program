#include<stdio.h>
#include<string.h>
const int maxn=1000+10;
int m[maxn];
int g[maxn];
int n1[10];
int n2[10];

int main()
{
    int n,test=1;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++) scanf("%d",&m[i]);
        printf("Game %d:\n",test++);
        while(1)
        {
            for(int i=0;i<n;i++) scanf("%d",&g[i]);
            if(!g[0]) break;
            int ans=0,anz=0;
            memset(n1,0,sizeof(n1));
            memset(n2,0,sizeof(n2));
            for(int i=0;i<n;i++)
            {
                if(m[i]==g[i]) ans++;
                else
                {
                    if(n2[m[i]]) { n2[m[i]]--; anz++; }
                    else n1[m[i]]++;
                    if(n1[g[i]]) { n1[g[i]]--; anz++; }
                    else n2[g[i]]++;
                }
            }
            printf("    (%d,%d)\n",ans,anz);
        }
    }
    return 0;
}
