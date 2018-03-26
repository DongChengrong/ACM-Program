#include<stdio.h>
#include<math.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        double sum = 0;
        for(int i = 1; i <= n; i++)
            sum += log10(i);
        printf("%d\n",(int)sum + 1);
    }
    return 0;
}
