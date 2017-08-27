#include<cstdio>
using namespace std;

int n;

int slove()
{
    int count = n;
    for(int i = 1; i <= n; i++)
    {
        int j = i;
        while(j)
        {
            int a = j % 10;
            if(a == 4) { count--; break; }
            j /= 10;
        }
    }
    return count;
}

int main()
{
    int Test;
    scanf("%d",&Test);
    for(int i = 1; i <= Test; i++)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",i,slove());
    }
    return 0;
}
