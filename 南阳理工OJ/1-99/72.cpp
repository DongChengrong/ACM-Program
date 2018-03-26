#include<stdio.h>

int main()
{
    double sum,x;
    sum = 0;
    for(int i = 0; i < 12; i++)
    {
        scanf("%lf",&x);
        sum += x;
    }
    printf("%.2lf\n",sum / 12);
    return 0;
}
