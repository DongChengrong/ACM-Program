#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int y,m,d;
        scanf("%d%d%d",&y,&m,&d);
        int date = 0;
        date = 31 * (m - 1) + d;
        if(y % 4 == 0 && m > 2) date -= 2;
        if(y % 4 != 0 && m > 2) date -= 3;
        if(m > 4) date -= 1;
        if(m > 6) date -= 1;
        if(m > 9) date -= 1;
        if(m > 11) date -= 1;
        printf("%d\n",date);
    }
    return 0;
}
