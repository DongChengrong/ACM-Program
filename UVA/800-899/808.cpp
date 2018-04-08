#include<stdio.h>
#include<stdlib.h>

const int maxn = 20000 + 10;
const int dir[5][2] = {{-1,1},{0,2},{1,1},{1,-1},{0,-2}};

struct Point
{
    int x,y;
    Point(){}
    Point(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
}P[maxn];   //点集

//以第一个点为原点，初始化坐标系
void init()
{
    int cnt = 1,x = 0,y = 0;

    //以下两行绘制了坐标系的原点
    P[cnt++] = Point(x,y);
    y -= 2;

    P[cnt++] = Point(x,y);  //记录下一个循环的起点

    for(int i = 1; i <= 60; i++)  //通过60次的循环完全可以绘制出60个点
    {
        for(int j = 0; j < 5; j++)  //改变方向
        {
            for(int k = 0; k < i; k++)  //每个方向上走几步
            {
                x += dir[j][0];
                y += dir[j][1];  //移动
                P[cnt++] = Point(x,y);
            }
        }

        //抵达下一个循环
        y -= 2;
        P[cnt++] = Point(x,y);
        for(int j = 0; j < i; j++)
        {
            x--; y--;
            P[cnt++] = Point(x,y);
        }
    }
}

int main()
{
    int a,b;
    init();
    while(scanf("%d%d",&a,&b) == 2 && a || b )
    {
        int result;
        int x = abs(P[a].x - P[b].x);
        int y = abs(P[a].y - P[b].y);
        if( x >= y) result = x;   //该公式可以找规律找到
        else result = x + (y - x) / 2;
        printf("The distance between cells %d and %d is %d.\n",a,b,result);
    }
    return 0;
}
