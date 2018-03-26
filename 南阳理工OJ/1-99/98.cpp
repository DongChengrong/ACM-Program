#include<stdio.h>

int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n >= 90) { printf("A\n"); continue; }
        if(n >= 80) { printf("B\n"); continue; }
        if(n >= 70) { printf("C\n"); continue; }
        if(n >= 60) { printf("D\n"); continue; }
        printf("E\n");
    }
    return 0;
}
