#include<stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        printf("2 %d %d\n",n,n);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                printf("%c",i < 26 ? i + 'a' : i - 26 + 'A');
            printf("\n");
        }

        printf("\n");

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                printf("%c", j < 26 ? j + 'a' : j - 26 + 'A');
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
