#include<cstdio>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;

int T,L,n;
const int MAXM=1000000;
const int MAXN=10000+10;
int vis[MAXM];

struct Pos
{
    int x;
    char dir;
}pos[MAXN];

struct Node
{
    int id;
    int x;
    char dir;
}M[MAXN];

int cmp(struct Node s1,struct Node s2)
{
    return s1.x<s2.x;
}

int cmp2(struct Node s1,struct Node s2)
{
    return s1.id<s2.id;
}

int cmp3(struct Pos s1,struct Pos s2)
{
    return s1.x<s2.x;
}

int main()
{
    int Test;
    scanf("%d",&Test);
    for(int kase=1;kase<=Test;kase++)
    {
        map<int,int> m;
        scanf("%d%d%d",&L,&T,&n);
        for(int i=0;i<n;i++) { scanf("%d %c",&M[i].x,&M[i].dir); M[i].id=i; }
        sort(M,M+n,cmp);
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            if(M[i].dir=='L') { pos[i].x=M[i].x-T; pos[i].dir=M[i].dir; }
            else if(M[i].dir=='R') { pos[i].x=M[i].x+T; pos[i].dir=M[i].dir; }
            if(m.count(pos[i].x)==0) m[pos[i].x]=1;
            else if(m.count(pos[i].x)>0) m[pos[i].x]++;
        }
        sort(pos,pos+n,cmp3);
        for(int i=0;i<n;i++)
        {
            M[i].x=pos[i].x;
            M[i].dir=pos[i].dir;
        }
        sort(M,M+n,cmp2);
        printf("Case #%d:\n",kase);
        for(int i=0;i<n;i++)
        {
            if(M[i].x<0 || M[i].x>L) printf("Fell off\n");
            else if(m[M[i].x]>1) printf("%d Turning\n",M[i].x);
            else printf("%d %c\n",M[i].x,M[i].dir);
        }
        printf("\n");
    }
    return 0;
}
