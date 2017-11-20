#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 10000 + 10;
const char dir[][10] = {"L","Turning","R"};

//蚂蚁结构体
struct Ant
{
    int id;  //每只蚂蚁的ID
    int p;   //蚂蚁的位置;
    int d;  //蚂蚁的方向,-1向左，0相撞，1向右
    bool operator < (const Ant & a) const  //自定义小于号
    {
        return p < a.p;
    }
};

Ant before[maxn],after[maxn];  //起始状态和终态
int order[maxn];  //每个id的蚂蚁对应的在终态中的位置

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 1; i <= T; i++)
    {
        printf("Case #%d:\n",i);
        int l,n,t;
        scanf("%d%d%d",&l,&t,&n);

        for(int i = 0; i < n; i++)
        {
            int p,d;
            char c;
            scanf("%d %c",&p,&c);
            d = (c == 'L' ? -1 : 1);
            before[i] = (Ant){i,p,d};
            after[i] = (Ant){0,p + t * d ,d};
        }

        sort(before,before+n);
        sort(after,after+n);

        for(int i = 0; i < n; i++)
            order[before[i].id] = i;

        //判断相撞的情况
        for(int i = 0; i < n - 1; i++)
            if(after[i].p == after[i + 1].p)
                after[i].d = after[i + 1].d = 0;

        //输出结果
        for(int i = 0; i < n; i++)
        {
            int pos = order[i];
            if(after[pos].p <0 || after[pos].p > l) printf("Fell off\n");
            else printf("%d %s\n",after[pos].p,dir[after[pos].d + 1]);
        }
        printf("\n");

    }
    return 0;
}
