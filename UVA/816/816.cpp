#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

//适用于本体的数据结构
struct Node
{
    int r,c,dir;  //坐标及方向
    Node(int r=0,int c=0,int dir=0):r(r),c(c),dir(dir){}
};

const int maxn=10;
const int dr[]={-1,0,1,0};
const int dc[]={0,1,0,-1};
const char *dirs="NESW";
const char *turns="FLR";
int d[maxn][maxn][4];
Node p[maxn][maxn][4];
int have_edge[maxn][maxn][4][3];
int r0,c0,r1,c1,r2,c2,dir;

int dir_id(char c)
{
    return strchr(dirs,c)-dirs;
}

int turn_id(char c)
{
    return strchr(turns,c)-turns;
}

//行走
Node walk(Node u,int i)
{
    int dir=u.dir;
    if(i==1) dir=(dir+3)%4;
    if(i==2) dir=(dir+1)%4;
    return Node(u.r+dr[dir],u.c+dc[dir],dir);
}

//判断是否越界
bool inside(Node u)
{
    return u.r>=1 && u.c>=1 && u.r<=9 && u.c<=9 ;
}

//读取测试数据
bool read_case()
{
    int r,c;
    char s1[100],s2[100];
    memset(have_edge,0,sizeof(have_edge));

    scanf("%s",s1);
    if(!strcmp(s1,"END")) return false;
    scanf("%d%d%s%d%d",&r0,&c0,s2,&r2,&c2);

    printf("%s\n",s1);
    dir=dir_id(s2[0]);
    //计算出去后的位置
    r1=r0+dr[dir]; c1=c0+dc[dir];
    while(1)
    {
        scanf("%d",&r);
        if(r==0) break;
        scanf("%d",&c);
        while(scanf("%s",s1)==1 && s1[0]!='*')
        {
            for(int i=1;i<strlen(s1);i++)
            {
                have_edge[r][c][dir_id(s1[0])][turn_id(s1[i])]=1;
            }
        }
    }
    return true;
}

//输出路径
void print(Node u)
{
    vector<Node> nodes;
    while(1)
    {
        nodes.push_back(u);
        if(d[u.r][u.c][u.dir]==0) break;
        u=p[u.r][u.c][u.dir];
    }
    nodes.push_back(Node(r0,c0,dir));
    int cnt=0;
    for(int i=nodes.size()-1;i>=0;i--)
    {
        if(cnt%10==0) printf(" ");
        printf(" (%d,%d)",nodes[i].r,nodes[i].c);
        if(++cnt%10==0) printf("\n");
    }
    if(nodes.size()%10!=0) printf("\n");
}

//解决问题
void solve()
{
    queue<Node> q;
    Node u(r1,c1,dir);
    memset(d,-1,sizeof(d));
    d[u.r][u.c][u.dir]=0;
    q.push(u);
    while(!q.empty())
    {
        Node u=q.front(); q.pop();
        if(u.r==r2 && u.c==c2) { print(u); return; }
        for(int i=0;i<3;i++)
        {
            Node v=walk(u,i);
            if(have_edge[u.r][u.c][u.dir][i] && inside(v) && d[v.r][v.c][v.dir]<0)
            {
                d[v.r][v.c][v.dir]=d[u.r][u.c][u.dir]+1;
                p[v.r][v.c][v.dir]=u;
                q.push(v);
            }
        }
    }
    printf("  No Solution Possible\n");
}

int main()
{
    while(read_case()) solve();
    return 0;
}
