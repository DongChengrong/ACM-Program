#include<stdio.h>

//判断是否是闰年
bool is_leap_year(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

//得到下一个闰年
int next_leap_year(int y)
{
    y += 4;
    while(!is_leap_year(y)) y+= 4;
    return y;
}

int main()
{
    int T,y,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&y,&n);

        while(!is_leap_year(y)) y += 4 - (y % 4);   //得到第一个闰年
        for(int i = 1; i < n; i++)  //得到第n个闰年
            y = next_leap_year(y);

        printf("%d\n",y);

    }
    return 0;
}
