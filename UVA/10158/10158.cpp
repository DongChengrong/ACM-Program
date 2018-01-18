#include<stdio.h>
#include<vector>
using namespace std;

const int maxn = 10000 + 10;
int n;
int pa[2 * maxn];    //前n个数代表朋友，后n个数代表敌人

//初始化
void init(int n)
{
    for(int i = 0; i < 2 * n; i++)   //朋友
        pa[i] = i;
}

//并查集
int findset(int x)
{
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

//读取数据
bool read_data(int &c, int &x, int &y)
{
    if(scanf("%d%d%d",&c,&x,&y) != 3)
        return false;
    if(c == 0)
        return false;
    return true;
}

//设置朋友
void set_friends(int x, int y)
{
    int fx,fy;
    int ex,ey;
    fx = findset(x); fy = findset(y);
    ex = findset(x + n); ey = findset(y + n);

    if(fx == ey || fy == ex)
        printf("-1\n");
    else
    {
        pa[fx] = fy;
        pa[ex] = ey;
    }
}

//设置敌人
void set_enemies(int x, int y)
{
    int fx,fy;
    int ex,ey;
    fx = findset(x); fy = findset(y);
    ex = findset(x + n); ey = findset(y + n);
    if(fx == fy)
        printf("-1\n");
    else
    {
        pa[fx] = ey;
        pa[fy] = ex;
    }
}

//是不是朋友
void are_friends(int x, int y)
{
    int fx,fy;
    fx = findset(x); fy = findset(y);
    printf("%d\n",fx == fy ? 1 : 0);
}

//是不是敌人
void are_enemies(int x, int y)
{
    int fx,fy;
    int ex, ey;
    fx = findset(x); fy = findset(y);
    ex = findset(x + n); ey = findset(y + n);
    if(fx == ey || fy == ex)
        printf("1\n");
    else
        printf("0\n");
}

void operate(int c, int x, int y)
{
    if(c == 1) set_friends(x,y);
    if(c == 2) set_enemies(x,y);
    if(c == 3) are_friends(x,y);
    if(c == 4) are_enemies(x,y);
}

int main()
{
    int c,x,y;
    scanf("%d",&n);
    init(n);
    while(read_data(c,x,y))    //不断读取并执行指令
        operate(c,x,y);
    return 0;
}
