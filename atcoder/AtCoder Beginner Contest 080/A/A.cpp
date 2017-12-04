#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int a,b,n;
    while(scanf("%d%d%d",&a,&n,&b) == 3)
    {
        printf("%d\n",min(a * n, b));
    }
    return 0;
}
