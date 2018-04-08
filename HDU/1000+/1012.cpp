#include<stdio.h>

double f(int n)
{
    if(n == 1 || n == 0)
        return 1;
    double res = 1;
    for(int i = 1; i <= n; i++)
        res *= i;
    return (double)res;
}

int main()
{
    printf("n e\n- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    for(int i = 3; i <= 9; i++)
    {
        double res = 0;
        for(int j = 0; j <= i; j++)
            res += 1 / f(j);
        printf("%d %.9lf\n",i,res);
    }
    return 0;
}
