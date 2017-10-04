#include<stdio.h>

const int day[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int y,m,d,sum = 0;
        scanf("%d%d%d",&y,&m,&d);
        for(int i = 1;i < m; i++)
            sum += day[i];
        sum += d;
        if(y % 4 == 0 && m > 2) sum += 1;
        printf("%d\n",sum);
    }
}
