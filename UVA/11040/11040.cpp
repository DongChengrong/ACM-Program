#include<stdio.h>

const int maxn = 15;
int a[maxn][maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i = 1; i <= 9; i += 2)
            for(int j = 1; j <= i; j += 2)
                scanf("%d",&a[i][j]);

        for(int i = 3; i <= 9; i += 2)
            for(int j = 3; j <= i; j+=2)
                a[i][j - 1] = (a[i-2][j-2] - a[i][j] - a[i][j-2]) / 2;

        for(int i = 2; i <= 8; i+=2)
            for(int j = 1; j <= i; j++)
                a[i][j] = a[i+1][j] + a[i+1][j+1];

        for(int i = 1; i <= 9; i++)
        {
            printf("%d",a[i][1]);
            for(int j = 2; j <= i; j++)
                printf(" %d",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}
