#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b) == 2)
    {
        if(a == 0 || b == 0) printf("Signs can't be sure\n");
        else if(abs(a) + abs(b) == abs(a + b)) printf("Signs are not opposot\n");
        else printf("Signs are opposite\n");
    }
    return 0;
}
