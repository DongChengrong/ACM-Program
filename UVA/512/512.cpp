#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1000+10;
int r,c,n;

struct Node
{
    char c[5];
    int r1,r2,c1,c2;
    int a,x[20];
}cmd[maxn];

int simlate(int &r0,int &c0)
{
    for(int i=0;i<n;i++)
    {
        if(cmd[i].c[0]=='E')
        {
            if(cmd[i].r1==r0 && cmd[i].c1==c0)
            {
                r0=cmd[i].r2; c0=cmd[i].c2;
            }
            else if(cmd[i].r2==r0 && cmd[i].c2==c0)
            {
                c0=cmd[i].c1; r0=cmd[i].r1;
            }
        }
        else
        {
            int dr,dc; dr=dc=0;
            if(cmd[i].c[1]=='R')
            {
                for(int j=0;j<cmd[i].a;j++)
                {
                    if(cmd[i].x[j]==r0)
                    {
                        if(cmd[i].c[0]=='D') return 0;
                        else dr++;
                    }
                    else if(cmd[i].x[j]<r0)
                    {
                        if(cmd[i].c[0]=='D') dr--;
                        else dr++;
                    }
                }
            }
            else if(cmd[i].c[1]=='C')
            {
                for(int j=0;j<cmd[i].a;j++)
                {
                    if(cmd[i].x[j]==c0)
                    {
                        if(cmd[i].c[0]=='D') return 0;
                        else dc++;
                    }
                    else if(cmd[i].x[j]<c0)
                    {
                        if(cmd[i].c[0]=='D') dc--;
                        else dc++;
                    }
                }
            }
            r0+=dr; c0+=dc;
        }
    }
    return 1;
}

int main()
{
    int Test=0;
    while(scanf("%d%d",&r,&c)==2 && r)
    {
        scanf("%d",&n);
        if(Test) printf("\n");
        printf("Spreadsheet #%d\n",++Test);
        for(int i=0;i<n;i++)
        {
            scanf("%s",cmd[i].c);
            if(cmd[i].c[0]=='E') scanf("%d%d%d%d",&cmd[i].r1,&cmd[i].c1,&cmd[i].r2,&cmd[i].c2);
            else
            {
                scanf("%d",&cmd[i].a);
                for(int j=0;j<cmd[i].a;j++)
                    scanf("%d",&cmd[i].x[j]);
            }
        }
        int q,r0,c0;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d",&r0,&c0);
            printf("Cell data in (%d,%d) ",r0,c0);
            if(simlate(r0,c0)) printf("moved to (%d,%d)\n",r0,c0);
            else printf("GONE\n");
        }
    }
    return 0;
}
