#include<cstdio>
using namespace std;

int a,b,c;

int slove()
{
    int count = 0;
    while(1)
    {
        if(a + b > c) break;
        a += b;
        count ++;
    }
    return count;
}

int main()
{
    int Test;
    scanf("%d",&Test);
    for(int i = 1;i <= Test; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        printf("Case #%d: %d\n",i,slove());
    }
    return 0;
}
